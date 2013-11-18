################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/FeatureForm.cpp \
../src/FilmItem.cpp \
../src/FormFactory.cpp \
../src/PanelFactory.cpp \
../src/SceneTransitionPolicyProvider.cpp \
../src/ShowTime.cpp \
../src/ShowTimeEntry.cpp \
../src/ShowTimeFrame.cpp \
../src/ShowTimeMainForm.cpp \
../src/ShowTimeRegister.cpp \
../src/UpComingListPanel.cpp 

OBJS += \
./src/AppResourceId.o \
./src/FeatureForm.o \
./src/FilmItem.o \
./src/FormFactory.o \
./src/PanelFactory.o \
./src/SceneTransitionPolicyProvider.o \
./src/ShowTime.o \
./src/ShowTimeEntry.o \
./src/ShowTimeFrame.o \
./src/ShowTimeMainForm.o \
./src/ShowTimeRegister.o \
./src/UpComingListPanel.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/FeatureForm.d \
./src/FilmItem.d \
./src/FormFactory.d \
./src/PanelFactory.d \
./src/SceneTransitionPolicyProvider.d \
./src/ShowTime.d \
./src/ShowTimeEntry.d \
./src/ShowTimeFrame.d \
./src/ShowTimeMainForm.d \
./src/ShowTimeRegister.d \
./src/UpComingListPanel.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_USE_DA_ -D_DEBUG -I"C:\tizen-sdk/library" -I"C:\Users\surendran\Tizen\ShowTime\inc" -O0 -g3 -Wall -c -fmessage-length=0 -g -pg -funwind-tables -finstrument-functions -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.1/rootstraps/tizen-emulator-2.1.native" -I"C:/tizen-sdk/platforms/tizen2.1/rootstraps/tizen-emulator-2.1.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.1/rootstraps/tizen-emulator-2.1.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.1/rootstraps/tizen-emulator-2.1.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


