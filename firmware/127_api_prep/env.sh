#!/bin/bash
# Setup a base directory:
BASE=/Volumes/data/Users/fishie2610/Workspace/CMPE127_Prep/SJSU-Dev

# SJSUOne Board Settings:
#SJSUONEDEV=/dev/tty.usbserial-A503JOLS # Set this to your board ID
SJSUONEDEV=/dev/tty.usbserial-A103IKB9 # Set this to your board ID
SJSUONEBAUD=38400

# Project Target Settings:
# Sets the binary name, defaults to "firmware" (Optional)
PROJ=firmware

# Sets which DBC to generate, defaults to "DBG"
ENTITY=DBG

# Compiler and library settings:
# Selects compiler version to use
PATH=$PATH:$BASE/tools/gcc-arm-none-eabi-6-2017-q2-update/bin:$BASE/tools/Hyperload:$BASE/tools/Telemetry
LIB_DIR="$BASE/firmware/lib"

# Export everything to the environment
export PATH
export PROJ
export ENTITY
export LIB_DIR
export SJSUONEDEV
export SJSUONEBAUD
export MAKEFLAGS
