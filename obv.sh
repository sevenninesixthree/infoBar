audioInfo=$(./audio.sh)
energyInfo=$(./energy_info)
dateInfo=$(./date_info.sh)
xsetroot -name " $audioInfo$energyInfo$dateInfo"
