<template>
  <div class="home">
    <hall-plan @dropped="chosenFigureParameters = null" :chosenParameters="chosenFigureParameters" :hall-width="20" :hall-height="20" :sector-size="1" />

    <div class="some-block-1" draggable="true" @dragstart="handleDragStart" data-width="2" data-height="3" data-background="#FF0000"></div>
    <div class="some-block-2" draggable="true" @dragstart="handleDragStart" data-width="1" data-height="6" data-background="#00FF00"></div>
    <div class="some-block-3" draggable="true" @dragstart="handleDragStart" data-width="4" data-height="1" data-background="#0000FF"></div>
    
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
        chosenFigureParameters: {
            height: 0,
            width: 0
        }
    }
  },
  methods: {
    handleDragStart(e) {
      
      const width = parseInt(e.target.dataset.width);
      const height = parseInt(e.target.dataset.height);
      const background = e.target.dataset.background;
      this.figureChoose(2,3);
      e.dataTransfer.setData("plan/obj", JSON.stringify({ width, height, background }));
    },
    figureChoose(width,height) {
        this.chosenFigureParameters = {
            height: height,
            width: width
        }
    }
  }
}
</script>

<style lang="scss">
  
  .some-block-1 {
    width: 20px;
    height: 30px;
    background: red;
  }

  .some-block-2{
    width: 10px;
    height: 60px;
    background: #00FF00;
  }

  .some-block-3 {
    width: 40px;
    height: 10px;
    background: #0000FF;
  }
  
</style>