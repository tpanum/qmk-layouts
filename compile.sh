#!/bin/bash

BUILD_FOLDER=$(pwd)/.build
mkdir -p $BUILD_FOLDER

docker run --rm \
       -v $(pwd)/ergodox:/qmk_firmware/keyboards/ergodox_ez/keymaps/default \
       -v $(pwd)/kinesis:/qmk_firmware/keyboards/kinesis/keymaps/default \
       -v $BUILD_FOLDER:/qmk_firmware/.build \
       qmkfm/qmk_firmware \
       bash -c "qmk compile -kb ergodox_ez -km default && qmk compile -kb kinesis/stapelberg -km default"

mv $BUILD_FOLDER/ergodox_ez_default.hex ergodox_ez_tpanum.hex
mv $BUILD_FOLDER/kinesis_stapelberg_default.hex kinesis_stapelberg_tpanum.hex
