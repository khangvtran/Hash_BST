################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Book.cpp \
../src/Catalogue.cpp \
../src/HashTable.cpp 

OBJS += \
./src/Book.o \
./src/Catalogue.o \
./src/HashTable.o 

CPP_DEPS += \
./src/Book.d \
./src/Catalogue.d \
./src/HashTable.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


