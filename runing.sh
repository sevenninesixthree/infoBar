cd $(dirname $0)
./obv.sh

Amin=10
seconds=$(date +%S)
seconds=`expr $seconds % $Amin`
seconds=`expr $Amin - $seconds`
seconds=`expr $seconds % $Amin`

Asecond=1000000000
nano=$(date +%N)
nano=`expr $Asecond - $nano`
nano=`expr $nano % $Asecond`
nano=$(echo "scale=3;$nano/$Asecond"|bc)

sleep $seconds
sleep $nano

while true; do
  ./obv.sh
  sleep $Amin
done
