let currentStatus = 0;

function updateButton() {
    const button = document.getElementById("EspButton");
    
    if (currentStatus) {
        // Jika LED menyala
        EspButton.textContent = "Matikan";
        button.classList.remove("btn-success");
        button.classList.add("btn-danger");
        ledEspImage.src = "./assets/img/led_on.svg";
    } else {
        // Jika LED mati
        EspButton.textContent = "Nyalakan";
        button.classList.remove("btn-danger");
        button.classList.add("btn-success");
        ledEspImage.src = "./assets/img/led_off.svg";
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