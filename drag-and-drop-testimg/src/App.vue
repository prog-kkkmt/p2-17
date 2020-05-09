<template>
  <div id="app">
    <Home/>
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

<style lang="scss">
    *{
        margin: 0;
        padding: 0;
    }
    body{
        height: 100vh;
    }
    #app{
        height: 100%;
    }
</style>
