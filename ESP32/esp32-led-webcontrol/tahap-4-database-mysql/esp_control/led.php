<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/7.0.1/css/all.min.css" integrity="sha512-2SwdPD6INVrV/lHTZbO2nodKhrnDdJK9/kg2XD1r9uGqPo1cUbujc+IYdlYdEErWNu69gVcYgdxlmVmzTWnetw==" crossorigin="anonymous" referrerpolicy="no-referrer" />
</head>
<body>
    <div class="layouts">
        <section class="navbar">
        <h3>COBA CUY</h3>
        </section>
        <section class="page-title">
            <h3>LED CONTROL</h3>
        </section>
        <section class="leds">
            <div class="led">
                <img src="assets/led-off.png" class="led-image" id="ledEspImage" />
                <p class="led-location-text">ESP 32</p>
                <button class="led-submit" id="EspButton">
                    TOMBOL
                </button>
            </div>
        </section>
        <section class="bottombar">
            <ul>
                <li>
                    <a href="/esp_control"><i class="fa-solid fa-home"></i></a>
                </li>
                <li>
                    <a href="led.html"><i class="fa-solid fa-lightbulb"></i></a>
                </li>
                <li>
                    <a href="/"><i class="fa-solid fa-fan"></i></a>
                </li>
                <li>
                    <a href="/"><i class="fa-solid fa-user"></i></a>
                </li>
            </ul>
        </section>
    </div>
    <script src="main.js"></script>
</body>
</html>