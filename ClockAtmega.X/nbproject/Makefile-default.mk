#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c botton.c displ.c funct.c analog.c buzzer.c ds1302.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/botton.o ${OBJECTDIR}/displ.o ${OBJECTDIR}/funct.o ${OBJECTDIR}/analog.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/ds1302.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/botton.o.d ${OBJECTDIR}/displ.o.d ${OBJECTDIR}/funct.o.d ${OBJECTDIR}/analog.o.d ${OBJECTDIR}/buzzer.o.d ${OBJECTDIR}/ds1302.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/botton.o ${OBJECTDIR}/displ.o ${OBJECTDIR}/funct.o ${OBJECTDIR}/analog.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/ds1302.o

# Source Files
SOURCEFILES=main.c botton.c displ.c funct.c analog.c buzzer.c ds1302.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega8
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/c497b4c17ebb25fe35db858c1dda1b274362f80 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/botton.o: botton.c  .generated_files/flags/default/af77ec3aa6bd6fac95092a9034b56eafb0197ebd .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/botton.o.d 
	@${RM} ${OBJECTDIR}/botton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/botton.o.d" -MT "${OBJECTDIR}/botton.o.d" -MT ${OBJECTDIR}/botton.o -o ${OBJECTDIR}/botton.o botton.c 
	
${OBJECTDIR}/displ.o: displ.c  .generated_files/flags/default/a6ac69640b2a3346afb25399a791df4cbbaf6b9d .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/displ.o.d 
	@${RM} ${OBJECTDIR}/displ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/displ.o.d" -MT "${OBJECTDIR}/displ.o.d" -MT ${OBJECTDIR}/displ.o -o ${OBJECTDIR}/displ.o displ.c 
	
${OBJECTDIR}/funct.o: funct.c  .generated_files/flags/default/75cbd5820b25a064532ba113d7096e8dd794c750 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/funct.o.d 
	@${RM} ${OBJECTDIR}/funct.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/funct.o.d" -MT "${OBJECTDIR}/funct.o.d" -MT ${OBJECTDIR}/funct.o -o ${OBJECTDIR}/funct.o funct.c 
	
${OBJECTDIR}/analog.o: analog.c  .generated_files/flags/default/2e018cf2c38c52eedeb5b22d35a15c224ae786 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/analog.o.d 
	@${RM} ${OBJECTDIR}/analog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/analog.o.d" -MT "${OBJECTDIR}/analog.o.d" -MT ${OBJECTDIR}/analog.o -o ${OBJECTDIR}/analog.o analog.c 
	
${OBJECTDIR}/buzzer.o: buzzer.c  .generated_files/flags/default/b3084823f380da59e18cdde44d78a2877ee9b15a .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buzzer.o.d" -MT "${OBJECTDIR}/buzzer.o.d" -MT ${OBJECTDIR}/buzzer.o -o ${OBJECTDIR}/buzzer.o buzzer.c 
	
${OBJECTDIR}/ds1302.o: ds1302.c  .generated_files/flags/default/4ba797e841f56b4b2a06f34b6444b968bc45736a .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ds1302.o.d 
	@${RM} ${OBJECTDIR}/ds1302.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ds1302.o.d" -MT "${OBJECTDIR}/ds1302.o.d" -MT ${OBJECTDIR}/ds1302.o -o ${OBJECTDIR}/ds1302.o ds1302.c 
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/85d8950a71ad598620ed4d12dce761ec2c77454b .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/botton.o: botton.c  .generated_files/flags/default/4b38c253073ab52bdb3f1f80f96794acf66f9357 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/botton.o.d 
	@${RM} ${OBJECTDIR}/botton.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/botton.o.d" -MT "${OBJECTDIR}/botton.o.d" -MT ${OBJECTDIR}/botton.o -o ${OBJECTDIR}/botton.o botton.c 
	
${OBJECTDIR}/displ.o: displ.c  .generated_files/flags/default/3b63d3b8b61ae2d0aad27ef8bdb8adae1f973fed .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/displ.o.d 
	@${RM} ${OBJECTDIR}/displ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/displ.o.d" -MT "${OBJECTDIR}/displ.o.d" -MT ${OBJECTDIR}/displ.o -o ${OBJECTDIR}/displ.o displ.c 
	
${OBJECTDIR}/funct.o: funct.c  .generated_files/flags/default/1a282f625d212e160d8c281bda77126c52aaa0b4 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/funct.o.d 
	@${RM} ${OBJECTDIR}/funct.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/funct.o.d" -MT "${OBJECTDIR}/funct.o.d" -MT ${OBJECTDIR}/funct.o -o ${OBJECTDIR}/funct.o funct.c 
	
${OBJECTDIR}/analog.o: analog.c  .generated_files/flags/default/ff740b5483e8d2cba679022348a40cfd1217a8f2 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/analog.o.d 
	@${RM} ${OBJECTDIR}/analog.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/analog.o.d" -MT "${OBJECTDIR}/analog.o.d" -MT ${OBJECTDIR}/analog.o -o ${OBJECTDIR}/analog.o analog.c 
	
${OBJECTDIR}/buzzer.o: buzzer.c  .generated_files/flags/default/b93eeb5b61751609016115b7958579c8fd0c9e29 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buzzer.o.d" -MT "${OBJECTDIR}/buzzer.o.d" -MT ${OBJECTDIR}/buzzer.o -o ${OBJECTDIR}/buzzer.o buzzer.c 
	
${OBJECTDIR}/ds1302.o: ds1302.c  .generated_files/flags/default/ae0e492a531d22e1fd9664e89ecf23b40eaf08c3 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ds1302.o.d 
	@${RM} ${OBJECTDIR}/ds1302.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ds1302.o.d" -MT "${OBJECTDIR}/ds1302.o.d" -MT ${OBJECTDIR}/ds1302.o -o ${OBJECTDIR}/ds1302.o ds1302.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/ClockAtmega.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
