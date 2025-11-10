let currentStatus = 0;

function updateButton() {
    const button = document.getElementById("EspButton");
    
    if (currentStatus) {
        // Jika LED menyala
        EspButton.textContent = "MATIKAN LED";
        EspButton.style.backgroundColor = "blue";
        ledEspImage.src = "./assets/led-on.png";
    } else {
        // Jika LED mati
        EspButton.textContent = "NYALAKAN LED";
        EspButton.style.backgroundColor = "#579fff";
        ledEspImage.src = "./assets/led-off.png";
    }
}
// Ambil status awal
fetch("get_led_status.php")
    .then(res => res.text())
    .then(status => {
    currentStatus = parseInt(status);
    updateButton();
    });

document.getElementById("EspButton").addEventListener("click", () => {
    currentStatus = currentStatus ? 0 : 1;
    fetch("update_led.php", {
    method: "POST",
    headers: { "Content-Type": "application/x-www-form-urlencoded" },
    body: "status=" + currentStatus
    }).then(() => updateButton());
});