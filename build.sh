#!/bin/bash
rm .version
# Bash Color
green='\033[01;32m'
red='\033[01;31m'
blink_red='\033[05;31m'
restore='\033[0m'

clear

# Resources
THREAD="-j$(grep -c ^processor /proc/cpuinfo)"
KERNEL="Image"
DTBIMAGE="dtb"
DEFCONFIG="kylo_defconfig"

# Kernel Details
VER=".R9.angler"

# Paths
KERNEL_DIR=`pwd`
REPACK_DIR="${HOME}/My-Projects/keRneL/anykernel2"
PATCH_DIR="${HOME}/My-Projects/keRneL/anykernel2/patch"
MODULES_DIR="${HOME}/My-Projects/keRneL/anykernel2/modules"
ZIP_MOVE="${HOME}/My-Projects/keRneL/hybridubertc-ouT-oReO"
ZIMAGE_DIR="${HOME}/My-Projects/ROSiP/angler/arch/arm64/boot/"

# Functions
function clean_all {
		rm -rf $MODULES_DIR/*
		cd ~/My-Projects/ROSiP/angler/out/kernel
		rm -rf $DTBIMAGE
		git reset --hard > /dev/null 2>&1
		git clean -f -d > /dev/null 2>&1
		cd $KERNEL_DIR
		echo
		make clean && make mrproper
}

function make_kernel {
		echo
		make $DEFCONFIG
		make $THREAD

}

function make_modules {
		rm `echo $MODULES_DIR"/*"`
		find $KERNEL_DIR -name '*.ko' -exec cp -v {} $MODULES_DIR \;
}

function make_dtb {
		$REPACK_DIR/tools/dtbToolCM -2 -o $REPACK_DIR/$DTBIMAGE -s 2048 -p scripts/dtc/ arch/arm64/boot/
}


function make_boot {
		cp -vr $ZIMAGE_DIR/Image.gz-dtb ~/My-Projects/keRneL/anykernel2/zImage
}


function make_zip {
		cd ~/My-Projects/keRneL/anykernel2
		zip -r9 `echo $AK_VER`.zip *
		mv  `echo $AK_VER`.zip $ZIP_MOVE
		cd $KERNEL_DIR
}


DATE_START=$(date +"%s")


echo -e "${green}"
echo "-----------------"
echo "Making Kylo Kernel:"
echo "-----------------"
echo -e "${restore}"

while read -p "Do you want to use UBERTC(1-2)? " echoice
do
case "$echoice" in
	1 )
		export CROSS_COMPILE=${HOME}/My-Projects/ROSiP/aarch64-linux-android-6.x/bin/aarch64-linux-android-
		TC="UBER6.X"
		echo
		echo "Using UBERTC 6.0"
		break
		;;
	2 )
		export CROSS_COMPILE=${HOME}/My-Projects/ROSiP/aarch64-linux-android-7.x/bin/aarch64-linux-android-
		TC="UBER7.X"
		echo
		echo "Using UBERTC 7.0"
		break
		;;
	* )
		echo
		echo "Invalid try again!"
		echo
		;;
esac
done

# Vars
BASE_AK_VER="Kylo-HYBRIDUBERTC"
AK_VER="$BASE_AK_VER$VER"
export LOCALVERSION=~`echo $AK_VER`
export LOCALVERSION=~`echo $AK_VER`
export ARCH=arm64
export SUBARCH=arm64
export KBUILD_BUILD_USER=storm119
export KBUILD_BUILD_HOST=LMint

echo

while read -p "Do you want to clean stuffs (y/n)? " cchoice
do
case "$cchoice" in
	y|Y )
		clean_all
		echo
		echo "All Cleaned now."
		break
		;;
	n|N )
		break
		;;
	* )
		echo
		echo "Invalid try again!"
		echo
		;;
esac
done

echo

while read -p "Do you want to build?" dchoice
do
case "$dchoice" in
	y|Y )
		make_kernel
		make_dtb
		make_modules
		make_boot
		make_zip
		break
		;;
	n|N )
		break
		;;
	* )
		echo
		echo "Invalid try again!"
		echo
		;;
esac
done


echo -e "${green}"
echo "-------------------"
echo "Build Completed in:"
echo "-------------------"
echo -e "${restore}"

DATE_END=$(date +"%s")
DIFF=$(($DATE_END - $DATE_START))
echo "Time: $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds."
echo
