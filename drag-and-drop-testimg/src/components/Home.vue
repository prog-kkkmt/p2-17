<template>
  <div class="home">
    <div class="left-menu" @dragend="returnFurnuture">
        <div class="top-menu">
            <div class="categories">
                <div :class="'all ' + sectorMap" @click="sectorMap = false">
                    мебель
                </div>
                <div :class="'all ' + !sectorMap" @click="sectorMap = true">
                    области
                </div>
            </div>
            <div class="search">
                Поиск...
            </div>
            <div class="filters">
                фильтры
            </div>
        </div>
        <div class="all-furniture" v-if="!sectorMap">
            <div v-for="b in furnuture" 
                :key="b.id"
                class="furniture-block"
                draggable="true"
                @dragstart="handleDragStart($event,b.width,b.height,b.background,b.id)"
                :data-width="b.width"
                :data-height="b.height"
                :data-background="b.background"
            >
                <div class="block-img">
                    <div :style="`width: ${b.width}0px;height: ${b.height}0px;background: ${b.background}`">
                    </div>
                </div>
                <div class="info-about">
                    <div class="name">
                        {{b.name}}
                    </div>
                    <div class="stats-block">
                        <div class="stats-name">
                            <div class="what-stat">
                                Размер:
                            </div>
                            <div class="what-stat">
                                На складе:
                            </div>
                        </div>
                        <div class="stats-info">
                            <div class="stat-info">
                                {{`${b.width}:${b.height}`}}
                            </div>
                            <div class="stat-info">
                                {{b.stored}}
                            </div>
                        </div>
                    </div>
                    <div class="color" :style="'background: ' + b.background">
                    </div>
                </div>
            </div>
        </div>
        <div class="all-areas" v-if="sectorMap">
            <div v-for="a in areas" 
                :key="a.id"
                class="furniture-block"
                draggable="true"
                @dragstart="handleDragStart($event,b.width,b.height,b.background,b.id)"
                @click="()=>{choosenArea = (choosenArea == null || choosenArea != a) ? a : null }"
            >
                <div class="block-img">
                    <div :style="`width: 40px;height: 40px;background: ${a.background}`">
                    </div>
                </div>
                <div class="info-about">
                    <div :class="`name ${choosenArea == a ? 'chosenArea' : ''}`">
                        {{a.name}}
                    </div>
                </div>
            </div>
            <div :class="'btn re'+remap" @click="remap = !remap">remap</div>
        </div>
    </div>
    <hall-plan class="drop-map" @dropped="chosenFigureParameters = null"
        :remap="remap"
        :sectorMap="sectorMap"
        :chosenParameters="chosenFigureParameters" 
        :hall-width="26.294" 
        :hall-height="15.806"
        :sector-size="1"
        :choosenArea="choosenArea"
        />
  </div>
</template>

<script>
import HallPlan from '@/components/HallPlan'

export default {
  name: 'Home',
  components: {
    HallPlan
  },
  data(){
    return{
        chosenFigureParameters: null,
        remap: false,
        sectorMap: false,
        modes: "place",
        choosenArea: null,
        furnuture:[
            {
                name: "Стул",
                id: 0,
                width: .5,
                height: .5,
                background: "#5c7786",
                stored: 20
            },
            {
                name: "Стол",
                id: 1,
                width: 1,
                height: 1,
                background: "black",
                stored: 31
            },
            {
                name: "Фуршет",
                id: 2,
                width: .3,
                height: 3,
                background: "wheat",
                stored: 10
            },
            {
                name: "Фуршет2",
                id: 3,
                width: 5,
                height: .7,
                background: "#a83939",
                stored: 10
            },
            {
                name: "Большой стол",
                id: 4,
                width: 2,
                height: 4,
                background: "gray",
                stored: 10
            },
        ],
        areas:[
            {
                id: 0,
                name: "Бар",
                background: "#a5292966"
            },
            {
                id: 1,
                name: "Гардероб",
                background: "#a56e2966"
            },
            {
                id: 2,
                name: "Сцена",
                background: "#292da566"
            }
        ],
    }
  },
  methods: {
    handleDragStart(e,width,height,background,id) {
        this.furnuture[id].stored -= 1;
        this.chosenFigureParameters = {
            height: height,
            width: width,
            background: background,
            id: id
        }
        e.dataTransfer.setData("plan/obj", JSON.stringify({ width, height, background }));
    },
    returnFurnuture(){
        if(this.chosenFigureParameters){
            this.furnuture[this.chosenFigureParameters.id].stored += 1;
            this.chosenFigureParameters = null;
        }
    }
  }
}
</script>

<style lang="scss">
    $main: #efd38e;
    .home{
        display: flex;
        height: 100%;
        overflow: hidden;
    }
    .left-menu{
        position: relative;
        background: #f7f7f7;
        width: 400px;
        padding: 0 15px;
    }
    .categories{
        display: flex;
        justify-content: space-between;
        margin: 20px 0 15px 0;
    }
    .all{
        padding: 3px 35px;
        font-weight: bold;
        font-size: 20px;
        text-align: center;
        width: 100px;
        border-radius: 50px;
        transition: .3s;
        border: 1px solid $main;
        cursor: pointer;
    }
    .false{
        background: $main;
        color: white;
    }
    .true{
        color: $main;
    }
    .search{
        background: #efefef;
        font-weight: 300;
        border-radius: 50px;
        padding: 5px 20px;
        color: #9c9c9c;
        margin-bottom: 15px;
    }
    .filters{
        background: $main;
        font-weight: bold;
        border-radius: 50px;
        padding: 5px 20px;
        color: white;
        margin-bottom: 15px;
    }
    .furniture-block{
        padding: 10px 7px;
        background: white;
        display: flex;
        align-items: center;
        margin-bottom: 12px;
    }
    .block-img{
        width: 60px;
        height: 60px;
        background: rgb(233, 233, 233);
        display: flex;
        align-items: center;
        justify-content: center;
        margin-right: 10px;
    }
    .info-about{
        width: 70%;
        position: relative;
    }
    .stats-block{
        display: flex;
        justify-content: space-between;
    }
    .stats-info{
        display: flex;
        flex-direction: column;
        align-items: flex-end;
    }
    .color{
        width: 8px;
        height: 100%;
        position: absolute;
        top: 0;
        right: -30px;
    }
    .chosenArea{
        color: $main;
    }
    .name{
        font-weight: bold;
        font-size: 20px;
        margin-bottom: 2px;
    }
    .btn{
        font-weight: bold;
        text-align: center;
        transition: .3s;
        border: 1px solid $main;
        cursor: pointer;
        margin: 10px 0;
        padding: 10px 0;
        font-size: 21px;
        border-radius: 50px;
    }
</style>