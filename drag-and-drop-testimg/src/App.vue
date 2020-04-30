<template>
  <div id="app">
    <Home/>
    <div class="block">
        <div class="blend-mode">
            HOLY SHIT
        </div>
        <div class="blend-mode-line"></div>
    </div>
  </div>
</template>

<script>
import Home from "./components/Home.vue";
export default {
    components:{
        Home
    }
}
</script>

<style lang="scss" scoped>
    #app{
        display: flex;
        padding-top: 70px;
        flex-direction: column;
        align-items: center;
        justify-content: center;
    }
    .drag-elem{
        width: 50px;
        height: 50px;
        background: rgb(187, 4, 4);

    }
    .drag-areas{
        display: flex;
        align-items: center;
        justify-content: center;
        margin-top: 20px;
    }
    .hovered{
        background: rgb(185, 185, 185);
    }
    @keyframes shit{
        from{
            left: -20px;
        }
        to{
            left: 95px;
        }
    }
    .block{
        position: relative;
    }
    .blend-mode-line{
        background: black;
        height: 35px;
        width: 15px;
        animation: 2s shit infinite alternate linear;
        position: absolute;
        background-blend-mode: lighten;
        top: -3px;
    }
    .blend-mode{
        font-weight: bold;
        padding: 5px;
        color: white;
        background: black;
        background-blend-mode: lighten;
    }
</style>
