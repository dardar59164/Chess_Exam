class Joueurs{
    constructor({Tour,timer,timerID}){
        this.Tour = 0
        this.timer = 180
        this.timerID
    }
}

const tileSize = 100;

function ReadAndPrintBoard() {
    var myFile = this.files[0]
    var reader = new FileReader()


    reader.addEventListener('load',function(event){
        //Crée un tableau de lignes à partir du .txt
        var fileContentArray = event.target.result.split(/\r\n|\n/)

        //Resize le board pour coller au nombre de cases
        let board = document.querySelector('.wrap')
        let bgBoard = document.querySelector('#BoardBG')
        board.style.width = (parseInt(fileContentArray[0]) * tileSize) + "px"
        board.style.height = (parseInt(fileContentArray[0]) * tileSize) + "px"
        //Gestion Taille Background
        bgBoard.style.width = (parseInt(fileContentArray[0]) * tileSize) + "px"
        bgBoard.style.height = (parseInt(fileContentArray[0]) * tileSize) + "px"

        //Crée le nombre de cases voulues
        function getNextChar(char, increment){
            nb = increment % 8
            return String.fromCharCode(char.charCodeAt(0) + nb)
        }
        var rowNb = 0
        for (let i = 1; i < (parseInt(fileContentArray[0]) * parseInt(fileContentArray[0]) + 1); i++) {
            if ((i-1) % 8 == 0){
                rowNb++
            }

            let div = document.createElement('div')
            div.setAttribute('id',getNextChar('a',i - 1) + rowNb)
            div.setAttribute('name',"piece")
            div.classList.add(fileContentArray[i+64],"piece")
            if (i < parseInt(fileContentArray[0]) * 2){
                div.classList.add("playsDown")
            }
            board.appendChild(div)

        }
        
    })
    reader.readAsText(myFile)
    document.querySelectorAll('span').forEach(item =>{
        item.style.display = "block"
    })
}
document.getElementById('inputFileBoard').addEventListener('change',ReadAndPrintBoard)

//Game Timer
let White_Timer = document.getElementById('White-Timer')
let Black_Timer = document.getElementById('Black-Timer')
let W_TotalTime = 240
let B_TotalTime = 240
var B_timerID
var W_timerID
var swap = 0
//Réduit le timer Blanc
function W_decreaseTimer(){
    White_Timer.innerHTML = W_TotalTime
    if (W_TotalTime > 0  && swap === 0){
        W_TimerID = setTimeout(() => {
            W_decreaseTimer()
            W_TotalTime--
        }, 1000)
    }
}

//Réduit le timer Noir
function B_decreaseTimer(){
    Black_Timer.innerHTML = B_TotalTime
    if (B_TotalTime > 0 && swap === 1){
        B_timerID = setTimeout(() => {
            B_TotalTime--
            B_decreaseTimer()
        }, 1000);   
    }
}

//Condition d'arrêt de l'un ou l'autre timer
function swapTimer(){
    if (swap === 0){
        swap = 1
        Black_Timer.style.background = "cyan"
        White_Timer.style.background = "none"
    } else {
        swap = 0
        Black_Timer.style.background = "none"
        White_Timer.style.background = "cyan"
    }
}
Black_Timer.addEventListener('click',swapTimer)
Black_Timer.addEventListener('click',W_decreaseTimer)
White_Timer.addEventListener('click',swapTimer)
White_Timer.addEventListener('click',B_decreaseTimer)