<template>
	<canvas 
        tabindex="-1" 
        @mousedown="handleMouseDown" 
        @mousemove="mouseCheck" 
        @mouseup="releaseMouse" 
        @drop="mousePlace" 
        @mousewheel="canvasScale"
        @keydown="figureChange"
        @dragover="onDragOver"
        ref="canvas" 
        width="1400" 
        height="600"
    ></canvas>
</template>
<script>
    export default {
        props: {
            hallWidth: {
                type: Number,
                required: true
            },
            hallHeight: {
                type: Number,
                required: true
            },
            sectorSize: {
                type: Number,
                default: 1
            },
            chosenParameters:{
                type: Object,
                default: ()=>{}
            }
        },
        data(){
            return{
                scale: 20,
                moveViewportActive: false,
                moveObjectActive: false,
                viewportOffset: { 
                    x: 0, 
                    y: 0 
                },
                planObjects: [],
                activeObject: null,
                isHovered: false,
                mousePos:{
                    x : 0,
                    y : 0
                }
            }
        },
        methods:{
            clamp(num,min,max){
                return num <= min ? min : num >= max ? max : num;
            },
            mapToLocal(p){
                return {
                    x: (p.x - this.$refs.canvas.offsetLeft) / this.scale - this.viewportOffset.x,
                    y: (p.y - this.$refs.canvas.offsetTop) / this.scale - this.viewportOffset.y
                };
            },
            renderGrid(ctx) {
                ctx.strokeStyle = "#000000";

                ctx.beginPath();

                ctx.strokeRect(0, 0, this.$refs.canvas.width, this.$refs.canvas.height);

                ctx.stroke();

                ctx.strokeStyle = "#dedede";

                ctx.beginPath();

                for (let i = 0; i < this.hallHeight * this.scale; i += this.sectorSize * this.scale) {
                    for (let j = 0; j < this.hallWidth * this.scale; j += this.sectorSize * this.scale) {

                        ctx.strokeRect(
                            j + this.viewportOffset.x * this.scale,
                            i + this.viewportOffset.y * this.scale,
                            this.sectorSize * this.scale,
                            this.sectorSize * this.scale
                        );
                    }
                }

                ctx.stroke();
            },
            mapToGrid(p){
                const cPoint = {
                    x: this.clamp(p.x, 0, this.hallWidth),
					y: this.clamp(p.y, 0, this.hallHeight)
				};
                return {
                    x: Math.floor(cPoint.x / this.sectorSize) * this.sectorSize,
                    y: Math.floor(cPoint.y / this.sectorSize) * this.sectorSize
                }
            },
            renderObjects(ctx) {
                const savedFillStyle = ctx.fillStyle;
                ctx.beginPath();
                for (const obj of this.planObjects) {
                    ctx.fillStyle = obj.background;
                    ctx.fillRect(
						(obj.pos.x + this.viewportOffset.x) * this.scale, 
						(obj.pos.y + this.viewportOffset.y) * this.scale, 
						obj.width * this.scale, 
						obj.height * this.scale
					);
                }

                ctx.stroke();

                ctx.fillStyle = savedFillStyle;
            },
            renderGhost(ctx){
                const savedFillStyle = "grey";
                ctx.beginPath();
                ctx.fillStyle = "gray";
                let dot = this.mapToGrid(this.mapToLocal(this.mousePos));
                ctx.fillRect(
                    (dot.x + this.viewportOffset.x) * this.scale, 
                    (dot.y + this.viewportOffset.y) * this.scale, 
                    this.chosenParameters.width * this.scale,
                    this.chosenParameters.height * this.scale
                );
                ctx.stroke();

                ctx.fillStyle = savedFillStyle;
            },
            renderPlan() {
                const ctx = this.$refs.canvas.getContext("2d");
                ctx.clearRect(0, 0, this.$refs.canvas.width, this.$refs.canvas.height);

                this.renderGrid(ctx);
                if(this.chosenParameters){
                    this.renderGhost(ctx);
                }
                this.renderObjects(ctx);
            },
            isPointInObject(obj, p){
                return (p.x >= obj.pos.x && p.x < obj.pos.x + obj.width)
						&& (p.y >= obj.pos.y && p.y < obj.pos.y + obj.height);
            },
            figureChange(e){
                if(e.key === "Delete" && this.isHovered != false){
                    this.planObjects.splice(this.planObjects.indexOf(this.isHovered),1);
                    this.renderPlan();
                }
            },
            canvasScale(e){
                if (e.deltaY > 0) {
                    this.scale--;
                } else {
                    this.scale++;
                }

                this.renderPlan();
            },
            handleMouseDown(e){
                const obj = this.cursorToObject({ x: e.clientX, y: e.clientY });
                
                if (obj == null) {
                    this.moveViewportActive = true;
                }
                else {
                    this.moveObjectActive = true;
                    this.activeObject = obj;
                }
            },
            releaseMouse(e){
                if (this.moveViewportActive) {
                    this.moveViewportActive = false;
                }
                else if (this.moveObjectActive && this.activeObject) {
                    this.activeObject.pos = this.mapToGrid(this.activeObject.pos);
                    this.activeObject = null;
                    
                    this.renderPlan();
                }
            },
            mouseCheck(e){
                const deltaX = e.movementX / this.scale;
                const deltaY = e.movementY / this.scale;
                if (this.cursorToObject({ x: e.clientX, y: e.clientY }) != null){
                    this.isHovered = this.cursorToObject({ x: e.clientX, y: e.clientY });
                }
                else{
                    this.isHovered = false;
                }
                if (this.moveViewportActive) {

                    this.viewportOffset.x += deltaX;
                    this.viewportOffset.y += deltaY;

                    this.renderPlan();
                }
                else if (this.moveObjectActive && this.activeObject) {

                    this.activeObject.pos.x += deltaX;
                    this.activeObject.pos.y += deltaY;
                    this.renderPlan();
                }
            },
            mousePlace(e){
                if (!e.dataTransfer)
                    return;

                const objData = JSON.parse(e.dataTransfer.getData("plan/obj"));
                const dropPoint = this.mapToLocal({ x: e.pageX, y: e.pageY });
                
                this.$emit("dropped")
                this.planObjects.push({
                    ...objData,
                    pos: this.mapToGrid(dropPoint)
                });
                
                this.renderPlan();
            },
            onDragOver(e){
                this.mousePos = {
                    x: e.clientX,
                    y: e.clientY
                };
                this.renderPlan();
                e.preventDefault();
            },
            pointToObject(p){
				return this.planObjects.find((obj) => this.isPointInObject(obj, p)) || null;
            },
            
            cursorToObject(cursorPos){
				return this.pointToObject(this.mapToGrid(this.mapToLocal(cursorPos)));
            }
        },
        mounted(){
            this.renderPlan();
        },
        watch:{
            chosenParameters(){
                this.renderPlan();
            }
        }
    }
</script>

<style>

</style>