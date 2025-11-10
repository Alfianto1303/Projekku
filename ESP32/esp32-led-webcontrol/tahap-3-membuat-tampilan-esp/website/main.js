const endpoint = "http://192.168.100.37";

function getEsp() {
    fetch(endpoint + "/esp", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON") {
            ledEsp.style.backgroundColor = "blue";
            ledEsp.innerText = "MATIKAN";
            ledEspImage.src = "./assets/led-on.png";
        }else {
            ledEsp.style.backgroundColor = "#579fff";
            ledEsp.innerText = "NYALAKAN";
            ledEspImage.src = "./assets/led-off.png";
        }
    });
}

function setEsp() {
    fetch(endpoint + "/esp", {
        method: "POST"
    }).then(response => response.text()).then(() => location.reload()); 
}

getEsp();