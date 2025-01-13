#pragma once

#include "Types.hpp"
#include "../ExportUtils.hpp"

// basic types
typedef enum SR_TYPE: u8 {
    SR_TYPE_NONE    = 0x00,
    SR_VOID         = 0x10,
    SR_UINT8        = 0x20,
    SR_INT8         = 0x30,
    SR_UINT16       = 0x40,
    SR_INT16        = 0x50,
    SR_UINT32       = 0x60,
    SR_INT32        = 0x70,
    SR_UINT64       = 0x80,
    SR_INT64        = 0x90,
    SR_FLOAT16      = 0xA0,
    SR_FLOAT32      = 0xB0,
    SR_FLOAT64      = 0xC0,
} SR_DATA_TYPE;

// scalar types
// upper 4 bits are the data usage
// lower 4 bits are the component count (NOTE: 0 represents 1 component, F represents 16 components)
typedef enum SR_SCALAR_TYPE: u8 {
    SR_UINT8_1      = 0x20,
    SR_UINT8_2      = 0x21,
    SR_UINT8_3      = 0x22,
    SR_UINT8_4      = 0x23,
    SR_UINT8_3X3    = 0x28,
    SR_UINT8_4X4    = 0x2F,

    SR_INT8_1       = 0x30,
    SR_INT8_2       = 0x31,
    SR_INT8_3       = 0x32,
    SR_INT8_4       = 0x33,
    SR_INT8_3X3     = 0x38,
    SR_INT8_4X4     = 0x3F,

    SR_UINT16_1     = 0x40,
    SR_UINT16_2     = 0x41,
    SR_UINT16_3     = 0x42,
    SR_UINT16_4     = 0x43,
    SR_UINT16_3X3   = 0x48,
    SR_UINT16_4X4   = 0x4F,

    SR_INT16_1      = 0x50,
    SR_INT16_2      = 0x51,
    SR_INT16_3      = 0x52,
    SR_INT16_4      = 0x53,
    SR_INT16_3X3    = 0x58,
    SR_INT16_4X4    = 0x5F,

    SR_UINT32_1     = 0x60,
    SR_UINT32_2     = 0x61,
    SR_UINT32_3     = 0x62,
    SR_UINT32_4     = 0x63,
    SR_UINT32_3X3   = 0x68,
    SR_UINT32_4X4   = 0x6F,

    SR_INT32_1      = 0x70,
    SR_INT32_2      = 0x71,
    SR_INT32_3      = 0x72,
    SR_INT32_4      = 0x73,
    SR_INT32_3X3    = 0x78,
    SR_INT32_4X4    = 0x7F,

    SR_UINT64_1     = 0x80,
    SR_UINT64_2     = 0x81,
    SR_UINT64_3     = 0x82,
    SR_UINT64_4     = 0x83,
    SR_UINT64_3X3   = 0x88,
    SR_UINT64_4X4   = 0x8F,

    SR_INT64_1      = 0x90,
    SR_INT64_2      = 0x91,
    SR_INT64_3      = 0x92,
    SR_INT64_4      = 0x93,
    SR_INT64_3X3    = 0x98,
    SR_INT64_4X4    = 0x9F,

    SR_FLOAT16_1    = 0xA0,
    SR_FLOAT16_2    = 0xA1,
    SR_FLOAT16_3    = 0xA2,
    SR_FLOAT16_4    = 0xA3,
    SR_FLOAT16_3X3  = 0xA8,
    SR_FLOAT16_4X4  = 0xAF,

    SR_FLOAT32_1    = 0xB0,
    SR_FLOAT32_2    = 0xB1,
    SR_FLOAT32_3    = 0xB2,
    SR_FLOAT32_4    = 0xB3,
    SR_FLOAT32_3X3  = 0xB8,
    SR_FLOAT32_4X4  = 0xBF,

    SR_FLOAT64_1    = 0xC0,
    SR_FLOAT64_2    = 0xC1,
    SR_FLOAT64_3    = 0xC2,
    SR_FLOAT64_4    = 0xC3,
    SR_FLOAT64_3X3  = 0xC8,
    SR_FLOAT64_4X4  = 0xCF,
} SR_SCALAR_TYPE;

// Texture formats with data types, upper 4 bits represent the number of channels, lower 4 bits represent the data usage
typedef enum SR_TEXTURE_FORMAT: u8 {
    SR_TEXTURE_NONE         = 0x00,

    // single channel
    SR_TEXTURE_R_UI8        = 0x12,
    SR_TEXTURE_R_I8         = 0x13,
    SR_TEXTURE_R_UI16       = 0x14,
    SR_TEXTURE_R_I16        = 0x15,
    SR_TEXTURE_R_UI32       = 0x16,
    SR_TEXTURE_R_I32        = 0x17,
    SR_TEXTURE_R_F16        = 0x1A,
    SR_TEXTURE_R_F32        = 0x1B,

    // two channels
    SR_TEXTURE_RG_UI8       = 0x22,
    SR_TEXTURE_RG_I8        = 0x23,
    SR_TEXTURE_RG_UI16      = 0x24,
    SR_TEXTURE_RG_I16       = 0x25,
    SR_TEXTURE_RG_UI32      = 0x26,
    SR_TEXTURE_RG_I32       = 0x27,
    SR_TEXTURE_RG_F16       = 0x2A,
    SR_TEXTURE_RG_F32       = 0x2B,

    // three channels
    SR_TEXTURE_RGB_UI8      = 0x32,
    SR_TEXTURE_RGB_I8       = 0x33,
    SR_TEXTURE_RGB_UI16     = 0x34,
    SR_TEXTURE_RGB_I16      = 0x35,
    SR_TEXTURE_RGB_UI32     = 0x36,
    SR_TEXTURE_RGB_I32      = 0x37,
    SR_TEXTURE_RGB_F16      = 0x3A,
    SR_TEXTURE_RGB_F32      = 0x3B,

    // four channels
    SR_TEXTURE_RGBA_UI8     = 0x42,
    SR_TEXTURE_RGBA_I8      = 0x43,
    SR_TEXTURE_RGBA_UI16    = 0x44,
    SR_TEXTURE_RGBA_I16     = 0x45,
    SR_TEXTURE_RGBA_UI32    = 0x46,
    SR_TEXTURE_RGBA_I32     = 0x47,
    SR_TEXTURE_RGBA_F16     = 0x4A,
    SR_TEXTURE_RGBA_F32     = 0x4B,

    // special formats
    SR_TEXTURE_DEPTH_16     = 0x51,
    SR_TEXTURE_DEPTH_24     = 0x52,
    SR_TEXTURE_DEPTH_32     = 0x53,
    SR_TEXTURE_DEPTH_24_STENCIL_8    = 0x54,
    SR_TEXTURE_DEPTH_32_STENCIL_8    = 0x55

} SR_TEXTURE_FORMAT;

namespace Syrius{

    /**
     * @brief This function will return the size of a usage in bytes
     *        An overloaded function is available for scalar types which does the same thing
     * @example SR_UINT8 -> 1 byte
     * @example SR_UINT16 -> 2 bytes
     * @example SR_UINT32 -> 4 bytes
     * @example SR_UINT64 -> 8 bytes
     * @param type The usage to get the size of
     * @return the number of bytes needed to store data of that usage
     */
    u8 SR_UTILS_API getTypeSize(SR_TYPE type);
    u8 SR_UTILS_API getTypeSize(SR_SCALAR_TYPE type);

    /**
     * @brief Returns the number of components in a scalar usage
     * @example SR_FLOAT32_1 -> 1
     * @example SR_FLOAT64_1 -> 1
     * @example SR_UINT8_4 -> 4
     * @param type
     * @return the number of components in the scalar usage
     */
    u8 SR_UTILS_API getScalarComponentCount(SR_SCALAR_TYPE type);

    /**
     * @brief Returns the base type of a scalar type
     * @example SR_FLOAT32_1 -> SR_FLOAT32
     * @example SR_UINT8_4 -> SR_UINT8
     * @param type scalar type
     * @return SR_TYPE
     */
    SR_TYPE SR_UTILS_API getScalarType(SR_SCALAR_TYPE type);

    /**
     * @brief Returns the number of channels in a texture format. The logic is the same as in getChannelFormatCount
     *        but then for texture formats.
     * @example SR_TEXTURE_RGBA_F32 -> 4
     * @example SR_TEXTURE_RG_I32 -> 2
     * @param format SR_TEXTURE_FORMAT
     * @return number of channels
     */
    u8 SR_UTILS_API getTextureChannelCount(SR_TEXTURE_FORMAT format);

    /**
     * @brief Returns the data type of a texture format
     * @example SR_TEXTURE_RGBA_F32 -> SR_FLOAT32
     * @example SR_TEXTURE_RG_I32 -> SR_INT32
     * @param format SR_TEXTURE_FORMAT
     * @return SR_TYPE
     */
    SR_TYPE SR_UTILS_API getTextureDataType(SR_TEXTURE_FORMAT format);

    u8 SR_UTILS_API getBytesPerPixel(SR_TEXTURE_FORMAT format);

}