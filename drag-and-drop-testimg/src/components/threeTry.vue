<template>
    <canvas tabindex="-1" @mousewheel="scale" id="three"></canvas>
</template>

<script>
import * as THREE from 'three'; 
export default {
    
    mounted(){
        let canvas = document.getElementById("three");
        canvas.setAttribute('width',1600);
        canvas.setAttribute('height',300);
        let renderer = new THREE.WebGLRenderer({canvas: canvas});
        renderer.setClearColor(0xffffff);
        let scene = new THREE.Scene();
        let camera = new THREE.PerspectiveCamera(45, 300 / 200, 0.1, 5000);
        camera.position.set(0,0,1000); 
        let light = new THREE.AmbientLight(0xffffff);
        scene.add(light);
        let map = new THREE.PlaneGeometry(500,500,10,10);
        let material = new THREE.MeshBasicMaterial({color: 0x000000,wireframe: true});
        let mesh = new THREE.Mesh(map,material);
        scene.add(mesh);
        renderer.render(scene,camera);
    }
}
</script>

<style>

</style>