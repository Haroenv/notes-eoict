/**
 * Falling cube script
 *
 * @author Rogier van der Linde <rogier.vanderlinde@kahosl.be>
 */

(function() {
    'use strict';

    // scene
    var camera, scene, renderer;

    // the game bottom plane
    var plane;

    // the cube
    var cube = {
        speedY: 0,
        accY: -0.981,
        side: 100,
        mesh: ''
    };

    // sounds
    var boing = new Audio('snd/boing.wav');
    var falling;
    if('webkitAudioContext' in window) {
        falling = new webkitAudioContext();
    } else {
        falling = new AudioContext();
    }
    var osc;

    /**
     * Initializes the game
     *
     */
    var init = function() {
        // scene
        scene = new THREE.Scene();

        // camera
        camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 1, 10000);
        camera.position.set(0, 500, 500);

        // spotlight 1
        var spotlight1 = new THREE.SpotLight();
        spotlight1.position.set(250, 600, 500);
        spotlight1.target.position.set(0, 0, 0);
        spotlight1.castShadow = true;
        scene.add(spotlight1);

        // spotlight 2
        var spotlight2 = new THREE.SpotLight();
        spotlight2.position.set(400, 400, 100);
        spotlight2.target.position.set(50, 15, 20);
        spotlight2.castShadow = true;
        scene.add(spotlight2);

        // plane
        plane = new THREE.Mesh(
            new THREE.PlaneGeometry(1200, 600, 8, 8),
            new THREE.MeshLambertMaterial({ color: 0xffEE00, wireframe: false })
        );
        plane.position.set(0, 0, 0);
        plane.castShadow = false;
        plane.receiveShadow = true;
        plane.rotation.x = -Math.PI / 2;
        scene.add(plane);

        // aim camera
        camera.lookAt(plane.position);

        // renderer
        renderer = new THREE.WebGLRenderer({ antialias: true });
        renderer.setSize(window.innerWidth, window.innerHeight);
        renderer.shadowMapEnabled = true;
        document.getElementById('viewport').appendChild(renderer.domElement);

        // add cube
        cube.mesh = new THREE.Mesh(
            new THREE.CubeGeometry(cube.side, cube.side, cube.side),
            // new THREE.MeshLambertMaterial( { color: 0x0000FF } )
            new THREE.MeshLambertMaterial( { color: 0x7f1734 } )
        );
        cube.mesh.position.set(0, 500, 0);
        cube.mesh.castShadow = true;
        scene.add(cube.mesh);

        //sound of the falling cube
        osc = falling.createOscillator();
        var amp = falling.createGain();
        amp.gain.value = 0.5;
        osc.connect(amp);
        amp.connect(falling.destination);
        osc.start();
    }

    // drop something with sound etc
    var drop = function(toDrop) {
        toDrop.mesh.position.y += toDrop.speedY;
        toDrop.speedY += toDrop.accY;
        osc.frequency.value = toDrop.mesh.position.y * 3;

        if (toDrop.mesh.position.y <= toDrop.side/2 && toDrop.speedY !== 0) {
            osc.stop();
            toDrop.mesh.position.y = toDrop.side/2;
            toDrop.speedY = -0.3 * toDrop.speedY;
            boing.play();
            console.log(toDrop.speedY);

            if (toDrop.speedY < Math.abs(1)) {
                toDrop.speedY = 0;
                toDrop.accY = 0;
                console.log('stop falling');
            }
        }
    }

    /**
     * Renders the scene
     *
     */
    var render = function() {
        drop(cube);
        renderer.render(scene, camera);
    };

    /**
     * Main animation loop
     *
     */
    var animate = function() {
        requestAnimationFrame(animate);
        render();
    };

    // start your engines!
    init();
    render();

    // start animating
    animate();

    var buttons = document.querySelectorAll('#buttons input[type=button]');

    var addCubeListeners = function(button) {
        button.addEventListener('click',function() {
            console.log('clicked ' + this.getAttribute('data-position'));
            cube.mesh.position.set(0, 500, 0);
        });
    }

    for (var i = 0; i < buttons.length; i++) {
        addCubeListeners(buttons[i]);
    }

})();
