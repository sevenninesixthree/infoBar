hour=$(date +%H)
icon=
if [ 6 -le $hour -a $hour -le 17 ]
then
  icon=
fi
echo $icon$(date +'%_I:%M %m-%d %A')
