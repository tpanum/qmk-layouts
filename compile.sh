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


# BUILD_FOLDER=$(pwd)/.build
# mkdir -p $BUILD_FOLDER

# docker run --rm \
#        -v $(pwd)/ergodox:/qmk_firmware/keyboards/ergodox_ez/keymaps/default \
#        -v $(pwd)/kinesis:/qmk_firmware/keyboards/kinesis/keymaps/default \
#        -v $BUILD_FOLDER:/qmk_firmware/.build \
#        ghcr.io/qmk/qmk_cli \
#        make "all"
#        # bash -c "qmk compile -kb ergodox_ez -km default && qmk compile -kb kinesis/stapelberg -km default"

# mv $BUILD_FOLDER/ergodox_ez_default.hex ergodox_ez_tpanum.hex
# mv $BUILD_FOLDER/kinesis_stapelberg_default.hex kinesis_stapelberg_tpanum.hex
