################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameState.cpp \
../src/MenuState.cpp \
../src/PauseState.cpp \
../src/PlayState.cpp \
../src/game.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/GameState.d \
./src/MenuState.d \
./src/PauseState.d \
./src/PlayState.d \
./src/game.d \
./src/main.d 

OBJS += \
./src/GameState.o \
./src/MenuState.o \
./src/PauseState.o \
./src/PlayState.o \
./src/game.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ozgur/eclipse_cpp_workspace/SFML_GameState_Template/Inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/GameState.d ./src/GameState.o ./src/MenuState.d ./src/MenuState.o ./src/PauseState.d ./src/PauseState.o ./src/PlayState.d ./src/PlayState.o ./src/game.d ./src/game.o ./src/main.d ./src/main.o

.PHONY: clean-src

