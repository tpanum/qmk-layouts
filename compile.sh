#!/bin/bash

if [ ! -d .qmk_firmware ]; then
    git clone https://github.com/qmk/qmk_firmware.git .qmk_firmware
else
	cd .qmk_firmware
	git pull
	cd ..
fi

cd .qmk_firmware


for keyboard in kinesis ergodox; do
    build_keyboard=$keyboard
    folder_keyboard=$keyboard

    if [ $keyboard == "ergodox" ]; then
	build_keyboard=ergodox_ez
	folder_keyboard=ergodox_ez
	variant_keyboard=base
    elif [ $keyboard == "kinesis" ]; then
	variant_keyboard=stapelberg
	build_keyboard=kinesis/$variant_keyboard
	folder_keyboard=kinesis/$variant_keyboard
    fi

    if [ -d keyboards/$folder_keyboard/keymaps/tpanum ]; then
	rm -r keyboards/$folder_keyboard/keymaps/tpanum
    fi
    mkdir -p keyboards/$folder_keyboard/keymaps/tpanum
    cp -r ../$keyboard/* keyboards/$folder_keyboard/keymaps/tpanum

    ./util/docker_build.sh $build_keyboard:tpanum
    short_build_keyboard=$(echo $build_keyboard | cut -d'/' -f1)
    mv .build/${short_build_keyboard}_${variant_keyboard}_tpanum.hex ../${keyboard}_tpanum.hex
done
