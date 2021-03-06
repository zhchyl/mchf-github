/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/**
  ******************************************************************************
  * @file    EEPROM_Emulation/inc/eeprom.h
  * @author  MCD Application Team
   * @version V1.0.0
  * @date    10-October-2011
  * @brief   This file contains all the functions prototypes for the EEPROM
  *          emulation firmware library.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EEPROM_H
#define __EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported constants --------------------------------------------------------*/
/* Define the size of the sectors to be used */
#define PAGE_SIZE               (uint32_t)0x4000  /* Page size = 16KByte */

/* Device voltage range supposed to be [2.7V to 3.6V], the operation will
   be done by word  */
#define VOLTAGE_RANGE           (uint8_t)VoltageRange_3

/* EEPROM start address in Flash */
#define EEPROM_START_ADDRESS  ((uint32_t)0x08008000) /* EEPROM emulation start address:
                                                  from sector2 : after 16KByte of used 
                                                  Flash memory */

/* Pages 0 and 1 base and end addresses */
#define PAGE0_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGE0_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (PAGE_SIZE - 1)))
#define PAGE0_ID               FLASH_Sector_2

#define PAGE1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x4000))
#define PAGE1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))
#define PAGE1_ID               FLASH_Sector_3

/* Used Flash pages for EEPROM emulation */
#define PAGE0                 ((uint16_t)0x0000)
#define PAGE1                 ((uint16_t)0x0001)

/* No valid page define */
#define NO_VALID_PAGE         ((uint16_t)0x00AB)

/* Page status definitions */
#define ERASED                ((uint16_t)0xFFFF)     /* Page is empty */
#define RECEIVE_DATA          ((uint16_t)0xEEEE)     /* Page is marked to receive data */
#define VALID_PAGE            ((uint16_t)0x0000)     /* Page containing valid data */

/* Valid pages in read and write defines */
#define READ_FROM_VALID_PAGE  ((uint8_t)0x00)
#define WRITE_IN_VALID_PAGE   ((uint8_t)0x01)

/* Page full define */
#define PAGE_FULL             ((uint8_t)0x80)

/* Variables' number */
//#define NB_OF_VAR             ((uint8_t)0x1ff)
#define NB_OF_VAR             ((uint16_t)0x1ff)		// to allow memories >


// EEPROM Variable locations - MAKE ABSOLUTELY CERTAIN that there are corresponding definitions in "main.c"!!!
enum
{
    VAR_ADDR_1=0xAA01,
    VAR_ADDR_2,
    VAR_ADDR_3,
    VAR_ADDR_4,
    VAR_ADDR_5,
    VAR_ADDR_6,
    VAR_ADDR_7,
    VAR_ADDR_8,
    VAR_ADDR_9,
    VAR_ADDR_10,
    VAR_ADDR_11,
    VAR_ADDR_12,
    VAR_ADDR_13,
    VAR_ADDR_14,
    VAR_ADDR_15,
    VAR_ADDR_16,
    VAR_ADDR_17,
    VAR_ADDR_18,
    VAR_ADDR_19,
    VAR_ADDR_20,
    VAR_ADDR_21,
    VAR_ADDR_22,
    VAR_ADDR_23,
    VAR_ADDR_24,
    VAR_ADDR_25,
    VAR_ADDR_26,
    VAR_ADDR_27,
    VAR_ADDR_28,
    VAR_ADDR_29,
    VAR_ADDR_30,
    VAR_ADDR_31,
    VAR_ADDR_32,
    VAR_ADDR_33,
    VAR_ADDR_34,
    VAR_ADDR_35,
    VAR_ADDR_36,
    VAR_ADDR_37,
    VAR_ADDR_38,
    VAR_ADDR_39,
    VAR_ADDR_40,
    VAR_ADDR_41,
    VAR_ADDR_42,
    VAR_ADDR_43,
    VAR_ADDR_44,
    VAR_ADDR_45,
    VAR_ADDR_46,
    VAR_ADDR_47,
    VAR_ADDR_48,
    VAR_ADDR_49,
    VAR_ADDR_50,
    VAR_ADDR_51,
    VAR_ADDR_52,
    VAR_ADDR_53,
    VAR_ADDR_54,
    VAR_ADDR_55,
    VAR_ADDR_56,
    VAR_ADDR_57,
    VAR_ADDR_58,
    VAR_ADDR_59,
    VAR_ADDR_60,
    VAR_ADDR_61,
    VAR_ADDR_62,
    VAR_ADDR_63,
    VAR_ADDR_64,
    VAR_ADDR_65,
    VAR_ADDR_66,
    VAR_ADDR_67,
    VAR_ADDR_68,
    VAR_ADDR_69,
    VAR_ADDR_70,
    VAR_ADDR_71,
    VAR_ADDR_72,
    VAR_ADDR_73,
    VAR_ADDR_74,
    VAR_ADDR_75,
    VAR_ADDR_76,
    VAR_ADDR_77,
    VAR_ADDR_78,
    VAR_ADDR_79,
    VAR_ADDR_80,
    VAR_ADDR_81,
    VAR_ADDR_82,
    VAR_ADDR_83,
    VAR_ADDR_84,
    VAR_ADDR_85,
    VAR_ADDR_86,
    VAR_ADDR_87,
    VAR_ADDR_88,
    VAR_ADDR_89,
    VAR_ADDR_90,
    VAR_ADDR_91,
    VAR_ADDR_92,
    VAR_ADDR_93,
    VAR_ADDR_94,
    VAR_ADDR_95,
    VAR_ADDR_96,
    VAR_ADDR_97,
    VAR_ADDR_98,
    VAR_ADDR_99,
    VAR_ADDR_100,
    VAR_ADDR_101,
    VAR_ADDR_102,
    VAR_ADDR_103,
    VAR_ADDR_104,
    VAR_ADDR_105,
    VAR_ADDR_106,
    VAR_ADDR_107,
    VAR_ADDR_108,
    VAR_ADDR_109,
    VAR_ADDR_110,
    VAR_ADDR_111,
    VAR_ADDR_112,
    VAR_ADDR_113,
    VAR_ADDR_114,
    VAR_ADDR_115,
    VAR_ADDR_116,
    VAR_ADDR_117,
    VAR_ADDR_118,
    VAR_ADDR_119,
    VAR_ADDR_120,
    VAR_ADDR_121,
    VAR_ADDR_122,
    VAR_ADDR_123,
    VAR_ADDR_124,
    VAR_ADDR_125,
    VAR_ADDR_126,
    VAR_ADDR_127,
    VAR_ADDR_128,
    VAR_ADDR_129,
    VAR_ADDR_130,
    VAR_ADDR_131,
    VAR_ADDR_132,
    VAR_ADDR_133,
    VAR_ADDR_134,
    VAR_ADDR_135,
    VAR_ADDR_136,
    VAR_ADDR_137,
    VAR_ADDR_138,
    VAR_ADDR_139,
    VAR_ADDR_140,
    VAR_ADDR_141,
    VAR_ADDR_142,
    VAR_ADDR_143,
    VAR_ADDR_144,
    VAR_ADDR_145,
    VAR_ADDR_146,
    VAR_ADDR_147,
    VAR_ADDR_148,
    VAR_ADDR_149,
    VAR_ADDR_150,
    VAR_ADDR_151,
    VAR_ADDR_152,
    VAR_ADDR_153,
    VAR_ADDR_154,
    VAR_ADDR_155,
    VAR_ADDR_156,
    VAR_ADDR_157,
    VAR_ADDR_158,
    VAR_ADDR_159,
    VAR_ADDR_160,
    VAR_ADDR_161,
    VAR_ADDR_162,
    VAR_ADDR_163,
    VAR_ADDR_164,
    VAR_ADDR_165,
    VAR_ADDR_166,
    VAR_ADDR_167,
    VAR_ADDR_168,
    VAR_ADDR_169,
    VAR_ADDR_170,
    VAR_ADDR_171,
    VAR_ADDR_172,
    VAR_ADDR_173,
    VAR_ADDR_174,
    VAR_ADDR_175,
    VAR_ADDR_176,
    VAR_ADDR_177,
    VAR_ADDR_178,
    VAR_ADDR_179,
    VAR_ADDR_180,
    VAR_ADDR_181,
    VAR_ADDR_182,
    VAR_ADDR_183,
    VAR_ADDR_184,
    VAR_ADDR_185,
    VAR_ADDR_186,
    VAR_ADDR_187,
    VAR_ADDR_188,
    VAR_ADDR_189,
    VAR_ADDR_190,
    VAR_ADDR_191,
    VAR_ADDR_192,
    VAR_ADDR_193,
    VAR_ADDR_194,
    VAR_ADDR_195,
    VAR_ADDR_196,
    VAR_ADDR_197,
    VAR_ADDR_198,
    VAR_ADDR_199,
    VAR_ADDR_200,
    VAR_ADDR_201,
    VAR_ADDR_202,
    VAR_ADDR_203,
    VAR_ADDR_204,
    VAR_ADDR_205,
    VAR_ADDR_206,
    VAR_ADDR_207,
    VAR_ADDR_208,
    VAR_ADDR_209,
    VAR_ADDR_210,
    VAR_ADDR_211,
    VAR_ADDR_212,
    VAR_ADDR_213,
    VAR_ADDR_214,
    VAR_ADDR_215,
    VAR_ADDR_216,
    VAR_ADDR_217,
    VAR_ADDR_218,
    VAR_ADDR_219,
    VAR_ADDR_220,
    VAR_ADDR_221,
    VAR_ADDR_222,
    VAR_ADDR_223,
    VAR_ADDR_224,
    VAR_ADDR_225,
    VAR_ADDR_226,
    VAR_ADDR_227,
    VAR_ADDR_228,
    VAR_ADDR_229,
    VAR_ADDR_230,
    VAR_ADDR_231,
    VAR_ADDR_232,
    VAR_ADDR_233,
    VAR_ADDR_234,
    VAR_ADDR_235,
    VAR_ADDR_236,
    VAR_ADDR_237,
    VAR_ADDR_238,
    VAR_ADDR_239,
    VAR_ADDR_240,
    VAR_ADDR_241,
    VAR_ADDR_242,
    VAR_ADDR_243,
    VAR_ADDR_244,
    VAR_ADDR_245,
    VAR_ADDR_246,
    VAR_ADDR_247,
    VAR_ADDR_248,
    VAR_ADDR_249,
    VAR_ADDR_250,
    VAR_ADDR_251,
    VAR_ADDR_252,
    VAR_ADDR_253,
    VAR_ADDR_254,
    VAR_ADDR_255,
    VAR_ADDR_256,
    VAR_ADDR_257,
    VAR_ADDR_258,
    VAR_ADDR_259,
    VAR_ADDR_260,
    VAR_ADDR_261,
    VAR_ADDR_262,
    VAR_ADDR_263,
    VAR_ADDR_264,
    VAR_ADDR_265,
    VAR_ADDR_266,
    VAR_ADDR_267,
    VAR_ADDR_268,
    VAR_ADDR_269,
    VAR_ADDR_270,
    VAR_ADDR_271,
    VAR_ADDR_272,
    VAR_ADDR_273,
    VAR_ADDR_274,
    VAR_ADDR_275,
    VAR_ADDR_276,
    VAR_ADDR_277,
    VAR_ADDR_278,
    VAR_ADDR_279,
    VAR_ADDR_280,
    VAR_ADDR_281,
    VAR_ADDR_282,
    VAR_ADDR_283,
    VAR_ADDR_284,
    VAR_ADDR_285,
    VAR_ADDR_286,
    VAR_ADDR_287,
    VAR_ADDR_288,
    VAR_ADDR_289,
    VAR_ADDR_290,
    VAR_ADDR_291,
    VAR_ADDR_292,
    VAR_ADDR_293,
    VAR_ADDR_294,
    VAR_ADDR_295,
    VAR_ADDR_296,
    VAR_ADDR_297,
    VAR_ADDR_298,
    VAR_ADDR_299,
    VAR_ADDR_300,
    VAR_ADDR_301,
    VAR_ADDR_302,
    VAR_ADDR_303,
    VAR_ADDR_304,
    VAR_ADDR_305,
    VAR_ADDR_306,
    VAR_ADDR_307,
    VAR_ADDR_308,
    VAR_ADDR_309,
    VAR_ADDR_310,
    VAR_ADDR_311,
    VAR_ADDR_312,
    VAR_ADDR_313,
    VAR_ADDR_314,
    VAR_ADDR_315,
    VAR_ADDR_316,
    VAR_ADDR_317,
    VAR_ADDR_318,
    VAR_ADDR_319,
    VAR_ADDR_320,
    VAR_ADDR_321,
    VAR_ADDR_322,
    VAR_ADDR_323,
    VAR_ADDR_324,
    VAR_ADDR_325,
    VAR_ADDR_326,
    VAR_ADDR_327,
    VAR_ADDR_328,
    VAR_ADDR_329,
    VAR_ADDR_330,
    VAR_ADDR_331,
    VAR_ADDR_332,
    VAR_ADDR_333,
    VAR_ADDR_334,
    VAR_ADDR_335,
    VAR_ADDR_336,
    VAR_ADDR_337,
    VAR_ADDR_338,
    VAR_ADDR_339,
    VAR_ADDR_340,
    VAR_ADDR_341,
    VAR_ADDR_342,
    VAR_ADDR_343,
    VAR_ADDR_344,
    VAR_ADDR_345,
    VAR_ADDR_346,
    VAR_ADDR_347,
    VAR_ADDR_348,
    VAR_ADDR_349,
    VAR_ADDR_350,
    VAR_ADDR_351,
    VAR_ADDR_352,
    VAR_ADDR_353,
    VAR_ADDR_354,
    VAR_ADDR_355,
    VAR_ADDR_356,
    VAR_ADDR_357,
    VAR_ADDR_358,
    VAR_ADDR_359,
    VAR_ADDR_360,
    VAR_ADDR_361,
    VAR_ADDR_362,
    VAR_ADDR_363,
    VAR_ADDR_364,
    VAR_ADDR_365,
    VAR_ADDR_366,
    VAR_ADDR_367,
    VAR_ADDR_368,
    VAR_ADDR_369,
    VAR_ADDR_370,
    VAR_ADDR_371,
    VAR_ADDR_372,
    VAR_ADDR_373,
    VAR_ADDR_374,
    VAR_ADDR_375,
    VAR_ADDR_376,
    VAR_ADDR_377,
    VAR_ADDR_378,
    VAR_ADDR_379,
    VAR_ADDR_380,
    VAR_ADDR_381,
    VAR_ADDR_382,
    VAR_ADDR_383
};

extern const uint16_t VirtAddVarTab[NB_OF_VAR];

//
//
/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint16_t EE_Init(void);
uint16_t EE_ReadVariable(uint16_t VirtAddress, uint16_t* Data);
uint16_t EE_WriteVariable(uint16_t VirtAddress, uint16_t Data);

#endif /* __EEPROM_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
