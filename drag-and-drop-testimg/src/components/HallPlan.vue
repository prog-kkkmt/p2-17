<template>
    <div class="block">
        <div class="top-info">
            <div class="name-hall">
                Baskey Hall / 23 чел.
            </div>
            <div class="name-editor">
                Андрейко Б.А.
            </div>
        </div>
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
            :width="this.canvasSize.width"
            :height="this.canvasSize.height"
        ></canvas>
    </div>
</template>
<script>
import { Polygon } from "./polygon";
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
            },
            remap:{
                type: Boolean,
                default: false
            },
            sectorMap:{
                type: Boolean,
                default: false
            },
            choosenArea:{
                true: Object,
                default: ()=>{}
            }
        },
        data(){
            return{
                Polygon: new Polygon(),
                scale: 50,
                moveViewportActive: false,
                viewportOffset: { 
                    x: 2, 
                    y: 2
                },
                planObjects: [],
                areas: [],
                activeObject: null,
                activeArea: null,
                isHovered: null,
                mousePos:{
                    x : 0,
                    y : 0
                },
                canvasSize:{
                    height: 0,
                    width: 0,
                },
                mapDots:[],
                startAreaPoint: null,
            }
        },
        methods:{
            renderPlan() {
                const ctx = this.$refs.canvas.getContext("2d");
                ctx.clearRect(0, 0, this.$refs.canvas.width, this.$refs.canvas.height);
                this.renderImg(ctx);
                if(this.sectorMap)
                    this.isHovered = this.cursorToArea(this.mapToLocal(this.mousePos));
                else
                    this.isHovered = this.pointToObject(this.mapToLocal(this.mousePos));
                if(this.chosenParameters){
                    this.renderGhost(ctx);
                }
                this.renderAreas(ctx);
                this.renderObjects(ctx);
                if(this.startAreaPoint){
                    this.areaDrow();
                }
            },
            renderImg(ctx) {
                ctx.strokeStyle = "#000000";
                let img = new Image();
                img.src = "/static/img/map1.png";
                ctx.drawImage(
                    img,
                    this.viewportOffset.x * this.scale,
                    this.viewportOffset.y * this.scale,
                    this.hallWidth * this.scale,
                    this.hallHeight * this.scale
                )
                this.drawPolygon(ctx);
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
                    ctx.strokeStyle = "5c5c5c";
                    ctx.strokeRect(
						(obj.pos.x + this.viewportOffset.x) * this.scale, 
						(obj.pos.y + this.viewportOffset.y) * this.scale, 
						obj.width * this.scale, 
						obj.height * this.scale
                    );
                }
                ctx.stroke();

                ctx.fillStyle = savedFillStyle;
            },
            renderAreas(ctx){
                ctx.beginPath();
                for(let ar of this.areas){
                    let st = this.mapToCanvas(ar.start);
                    let fn = this.mapToCanvas(ar.finish);
                    var p = document.createElement("canvas");
                    p.width=32;
                    p.height=16;
                    var pctx=p.getContext('2d');
                    var x0=36;
                    var x1=-4;
                    var y0=-2;
                    var y1=18;
                    var offset=32;
                    pctx.strokeStyle = "#0000007d";
                    pctx.lineWidth=2;
                    pctx.beginPath();
                    pctx.moveTo(x0,y0);
                    pctx.lineTo(x1,y1);
                    pctx.moveTo(x0-offset,y0);
                    pctx.lineTo(x1-offset,y1);
                    pctx.moveTo(x0+offset,y0);
                    pctx.lineTo(x1+offset,y1);
                    pctx.stroke();
                    ctx.fillStyle=ctx.createPattern(p,'repeat'); 
                    ctx.fillRect(st.x,st.y,fn.x - st.x,fn.y - st.y);


                    ctx.font = `${(fn.y - st.y)/10}px Roboto MS`;
                    // ctx.textAlign = "center";
                    // ctx.fillStyle = ar.background;
                    // ctx.fillRect(
                    //     st.x,
                    //     st.y,
                    //     fn.x - st.x,
                    //     fn.y - st.y
                    // );
                    ctx.fillStyle = "black";
                    ctx.textAlign = 'center';
                    ctx.fillText(ar.name,(st.x + fn.x)/2, (st.y + fn.y + 10)/2);
                }
                ctx.fill();
            },
            renderGhost(ctx){
                const savedFillStyle = "grey";
                ctx.beginPath();
                ctx.fillStyle = "grey";
                let dot = this.alligmentMap(this.mapToLocal(this.mousePos),this.chosenParameters);
                ctx.fillRect(
                    (dot.x + this.viewportOffset.x) * this.scale, 
                    (dot.y + this.viewportOffset.y) * this.scale, 
                    this.chosenParameters.width * this.scale,
                    this.chosenParameters.height * this.scale
                );
                ctx.stroke();

                ctx.fillStyle = savedFillStyle;
            },
            areaDrow(p = this.mousePos){
                let ctx = this.$refs.canvas.getContext("2d");
                p = this.mapToCanvas(this.mapToLocal(p));
                ctx.fillStyle = this.choosenArea.background;
                ctx.beginPath();
                let startP = this.mapToCanvas(this.startAreaPoint);
                ctx.fillRect(startP.x, startP.y,(p.x - startP.x),(p.y - startP.y));
                ctx.fill();
            },
            drawPolygon(ctx){
                let pM = this.Polygon.points;
                if(pM.length == 0){
                    return;
                }
                ctx.strokeStyle = "#000000";
                ctx.beginPath();
                let p = this.mapToCanvas(pM[0]);
                ctx.lineWidth = 5;
                ctx.moveTo(p.x, p.y);
                ctx.arc(p.x, p.y,4,0,2 * Math.PI);
                for(let i = 1; i < pM.length; i++){
                    p = this.mapToCanvas(pM[i]);
                    ctx.arc(p.x, p.y,4,0,2 * Math.PI);
                    ctx.lineTo(p.x,p.y);
                }
                ctx.closePath();
                ctx.stroke();
            },
            mapToLocal(p){
                return {
                    x: (p.x - this.$refs.canvas.offsetLeft) / this.scale - this.viewportOffset.x,
                    y: (p.y - this.$refs.canvas.offsetTop) / this.scale - this.viewportOffset.y
                };
            },
            mapToCanvas(p){
                return {
                    x: (p.x + this.viewportOffset.x) * this.scale,
                    y: (p.y + this.viewportOffset.y) * this.scale
                };
            },
            isPointInObject(obj, p){
                return (p.x >= obj.pos.x && p.x < obj.pos.x + obj.width)
						&& (p.y >= obj.pos.y && p.y < obj.pos.y + obj.height);
            },
            isPointInArea(obj, p){
                return (p.x >= obj.start.x && p.x < obj.finish.x)
						&& (p.y >= obj.start.y && p.y < obj.finish.y);
            },
            alligmentMap(p,obj){
                if(obj != null){
                    if(p.x > this.hallWidth - obj.width){
                        p.x -= p.x - (this.hallWidth - obj.width);
                    }
                    else if(p.x < 0){
                        p.x = 0;
                    }
                    if(p.y > this.hallHeight - obj.height){
                        p.y -= p.y - (this.hallHeight - obj.height);
                    }
                    else if(p.y < 0){
                        p.y = 0;
                    }
                }
                return p
            },
            alligmentObj(i,dropPoint,objData){
                let dpy = dropPoint.y;
                let dpx = dropPoint.x;
                if(!(dpy > i.pos.y + i.height || dpy + objData.height < i.pos.y || 
                        dpx > i.pos.x + i.width || dpx + objData.width < i.pos.x)){
                    let arrGr = [
                        i.pos.y + i.height - dpy, dpy + objData.height - i.pos.y,
                        i.pos.x + i.width - dpx, dpx + objData.width - i.pos.x
                    ];
                    switch (arrGr.indexOf(Math.min(...arrGr))) {
                        case 0:
                            dpy += arrGr[0];
                        break;
                        case 1:
                            dpy -= arrGr[1];
                        break
                        case 2:
                            dpx += arrGr[2];
                        break
                        case 3:
                            dpx -= arrGr[3];
                        break;
                    }
                }
                return {x : dpx, y : dpy};
            },
            figureChange(e){
                let mass = this.planObjects;
                let newObj = {};
                if(this.isHovered != null){
                    let obj = this.isHovered;
                    if(e.key === "r" || e.key === "к" || e.key === "R" || e.key ===  "К"){
                        newObj = {
                            background: obj.background,
                            height: obj.width,
                            pos: obj.pos,
                            width: obj.height
                        }
                        this.planObjects[mass.indexOf(obj)] = newObj;
                    }
                    else if(e.key === "Delete"){
                        if(this.sectorMap){
                            this.areas.splice(this.areas.indexOf(obj),1);
                        }
                        else{
                            this.planObjects.splice(mass.indexOf(obj),1);
                        }
                    }
                }
            },
            canvasScale(e){
                if (e.deltaY > 0) {
                    if(this.scale > 4){
                        this.scale--;
                    }
                } else {
                    if(this.scale < 100){
                        this.scale++;
                    }
                }
            },
            handleMouseDown(e){
                const obj = this.cursorToObject({ x: e.offsetX, y: e.offsetY });
                if(this.remap){
                    this.Polygon.addPoint(this.mapToLocal({ x: e.offsetX, y: e.offsetY }));
                }
                if(this.sectorMap && this.choosenArea != null && this.startAreaPoint == null){
                    this.startAreaPoint = this.mapToLocal({x: e.offsetX, y: e.offsetY});
                }
                else{
                    if (obj == null) {
                        this.moveViewportActive = true;
                    }
                    else {
                        this.activeObject = obj;
                    }
                }
            },
            releaseMouse(e){
                if(this.sectorMap && this.choosenArea != null){
                    this.areas.push({
                        start:this.startAreaPoint,
                        finish:this.mapToLocal(this.mousePos),
                        background: this.choosenArea.background,
                        name: this.choosenArea.name
                    });
                    this.startAreaPoint = null;
                }
                if (this.moveViewportActive) {
                    this.moveViewportActive = false;
                }
                else if (this.activeObject){
                    let massWithout = [...this.planObjects];
                    massWithout.splice(massWithout.indexOf(this.activeObject),1);
                    for(let i of massWithout){
                        this.activeObject.pos = this.alligmentObj(i,this.activeObject.pos,this.activeObject);
                    }
                    this.activeObject.pos = this.alligmentMap(this.activeObject.pos,this.activeObject);
                    this.activeObject = null;
                }
            },
            mouseCheck(e){
                const deltaX = e.movementX / this.scale;
                const deltaY = e.movementY / this.scale;
                this.mousePos = {
                    x: e.offsetX,
                    y: e.offsetY
                };
                if (this.moveViewportActive) {
                    this.viewportOffset.x += deltaX;
                    this.viewportOffset.y += deltaY;
                }
                else if (this.activeObject) {
                    this.activeObject.pos.x += deltaX;
                    this.activeObject.pos.y += deltaY;
                }
                else if (this.activeArea) {
                    this.activeObject.pos.x += deltaX;
                    this.activeObject.pos.y += deltaY;
                }
            },
            
            mousePlace(e){
                console.log(e);
                if (!e.dataTransfer)
                    return;
                const objData = JSON.parse(e.dataTransfer.getData("plan/obj"));
                let dropPoint = this.alligmentMap(this.mapToLocal({ x: e.offsetX, y: e.offsetY }),objData);
                this.$emit("dropped");
                for(let i of this.planObjects){
                    dropPoint = this.alligmentObj(i,dropPoint,objData);
                }
                this.planObjects.push({
                    ...objData,
                    pos: dropPoint
                });
            },
            onDragOver(e){
                this.mousePos = {
                    x: e.offsetX,
                    y: e.offsetY
                };
                e.preventDefault();
            },
            pointToObject(p){
				return this.planObjects.find((obj) => this.isPointInObject(obj, p)) || null;
            },
            cursorToArea(p){
                return this.areas.find((area) => this.isPointInArea(area, p)) || null;
            },
            cursorToObject(cursorPos){
				return this.pointToObject(this.mapToLocal(cursorPos));
            }
        },
        mounted(){
            setInterval(() => {
                this.renderPlan();
            },10);
            this.canvasSize = {
                width: window.innerWidth-400,
                height: window.innerHeight
            }
            this.scale = Math.min(this.canvasSize.width/(this.hallWidth+4),this.canvasSize.height/(this.hallHeight+4));
            //Math.floor(((this.canvasSize.width) * this.canvasSize.hight) / (this.hallWidth * this.hallHeight) / 65);
            this.viewportOffset = {
                x: ((this.canvasSize.width / this.scale - this.hallWidth * this.sectorSize) / 2),
                y: ((this.canvasSize.height / this.scale - this.hallHeight * this.sectorSize) / 2),
            }
        }
    }
</script>

<style lang="scss">
    canvas{
        outline: unset;
    }
    .block{
        position: relative;
    }
    .top-info{
        position: absolute; 
        display: flex;
        align-items: center;
        justify-content: space-between;
        font-weight: bold;;
        background: #f1f1f1;
        height: 45px;
        width: 100%;
        box-sizing: border-box;
        padding-left: 40px;
    }
    .name-editor{
        width: 200px;
        display: flex;
        justify-content: center;
        align-items: center;
        background: #e9e9e9;
        height: 100%;
    }
</style>