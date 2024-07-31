state=$(amixer get Master | grep Mono: | awk '{print $6}'| tr -d [])
if [ $state == off ]
then
  echo "| "
fi
