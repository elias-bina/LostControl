#!/bin/bash

git clone git@github.com:erincatto/box2d.git
cd box2d
mkdir build
cd build

cmake -DBOX2D_BUILD_TESTBED=OFF -DBUILD_SHARED_LIBS=ON ..
make
sudo make install

cd ../..
rm -rf box2d
