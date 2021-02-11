#!/bin/bash

mkdir -p deps
cd deps

echo "Installing box2d"
if ! [ -d box2d ] && ! git clone https://github.com/erincatto/box2d.git
then
    echo "Cannot download Box2D"
    exit 1
fi
cd box2d
mkdir -p build
cd build

if ! cmake -DCMAKE_INSTALL_PREFIX=/usr -DBOX2D_BUILD_TESTBED=ON -DBUILD_SHARED_LIBS=ON .. && make
then
    echo "Cannot build Box2D"
    exit 1
fi
if ! sudo make install && cd ../..
then
    echo "Cannot install Box2D"
    exit 1
fi

echo "Installing Thor"
if ! [ -d Thor ] && ! git clone https://github.com/Bromeon/Thor.git
then
    echo "Cannot download Thor"
    exit 1
fi

cd Thor
git checkout v2.0
mkdir -p build
cd build

if ! cmake -DCMAKE_INSTALL_PREFIX=/usr -DBUILD_SHARED_LIBS=ON .. && make
then 
    echo "Cannot build Thor"
    exit 1
fi
if ! sudo make install && cd ../..
then
    echo "Cannot install Thor"
    exit 1
fi

cd ..

echo "End of installation, you can safely remove deps folder if you want to"