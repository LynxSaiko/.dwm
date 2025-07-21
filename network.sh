#!/usr/bin/env sh

# YOU CAN EDIT THE LINES BELOW 
DEFAULT_DEVICE_NAME='battery_BAT0'
# YOU CAN EDIT THE LINES ABOVE # ! DO NOT EDIT VARIABLES BELOW ! # 

DEVICE_NAME=${1:-'battery_BAT0'}
PATH_PREFIX='/org/freedesktop/UPower/devices'
DEVICE_PATH="$PATH_PREFIX/$DEVICE_NAME"
# ! DO NOT EDIT VARIABLES ABOVE ! #

while true; do
       date '+%a %d %b %Y | %T' > /tmp/CurTime.tmp
       sleep 1s
done &

while true; do
        CPU=$(top -bn1 | grep load | awk '{printf "%.2f\n", $(NF-2)}')
        MEM=$(free -h | awk '/^Mem:/ {print $3}')
        LOCALTIME=$(< /tmp/CurTime.tmp)
        
        # Battery info (adjust if necessary)
        battery_info=$(upower -i $(upower -e | grep battery))
        BHT=$(echo "$battery_info" | awk -F':' '/voltage/ {print $2}' | xargs)
        TIME_TO_EMPTY=$(echo "$battery_info" | awk -F':' '/time to empty/ {print $2}' | xargs)
        
        # Network info using wpa_supplicant
        NET=$(iw dev wlan0 link | grep SSID | awk '{print $2}')   # Get connected SSID
        SIGNAL=$(iw dev wlan0 link | grep signal | awk '{print $2}')   # Get signal strength in dBm
        
        TOTALDOWN=$(ifconfig wlan0 | grep "RX bytes" | awk '{print $2}')  # Set wlan0 or wlan1
        TOTALUP=$(ifconfig wlan0 | grep "TX bytes" | awk '{print $6}')   # Set wlan0 or wlan1
        
        # Update xsetroot with the new info
        xsetroot -name "CPU:$CPU | Mem:$MEM | Net: $NET Signal: $SIGNAL dBm | up: $TOTALUP down: $TOTALDOWN | $LOCALTIME | .$BHT | W.$TIME_TO_EMPTY"
        
        sleep 1s
done &
