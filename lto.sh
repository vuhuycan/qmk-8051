#!/bin/bash -f

kb=${1:-'reccarz_kw75s'}
km=${1:-'default'}
#km=${1:-'vial'}



#qmk clean 
#qmk generate-compilation-database 
#qmk compile 

./util/sdcc_MCS51_rm/sdcc_MCS51_rm.py -d .build/obj_${kb}_${km}/ \
 -e USB_DeviceInterrupt Timer0_ISR send_mouse send_extra send_keyboard keyboard_leds generate_tick_event \
 get_u16_str get_u8_str \
 > ./${kb}_${km}.sdcc_mcs51_rm.log 

asmlist=$(find .build/obj_${kb}_${km} -name "*asm" -type f) 
for file in $asmlist
    do
    # move .asm to .asm.bk :
    mv "${file}" "${file}.bak"
    # move .asm.mod to .asm :
    mv "${file}.mod" "${file}" 
done 

