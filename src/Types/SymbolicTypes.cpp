#include "../../include/SyriusUtils/Types/SymbolicTypes.hpp"
#include "../../include/SyriusUtils/Logger/LoggerMacros.hpp"

namespace Syrius{

    u8 getTypeSize(SR_TYPE type){
        switch (type) {
            case SR_TYPE_NONE:  return 0;
            case SR_VOID:       return 0;
            case SR_UINT8:      return 1;
            case SR_INT8:       return 1;
            case SR_UINT16:     return 2;
            case SR_INT16:      return 2;
            case SR_UINT32:     return 4;
            case SR_INT32:      return 4;
            case SR_UINT64:     return 8;
            case SR_INT64:      return 8;
            case SR_FLOAT16:    return 2;
            case SR_FLOAT32:    return 4;
            case SR_FLOAT64:    return 8;
            default: {
                SR_LOG_WARNING("Converter", "Unknown type {} given to converter", type);
                return 0;
            }
        }
    }
    u8 getTypeSize(SR_SCALAR_TYPE type){
        u8 trunc = type << 4;
        u8 componentCount = (trunc >> 4) + 1;
        return componentCount * getTypeSize(static_cast<SR_TYPE>((type >> 4) << 4));
    }

    u8 getScalarComponentCount(SR_SCALAR_TYPE type){
        u8 trunc = type << 4;
        return (trunc >> 4) + 1;
    }

    SR_TYPE getScalarType(SR_SCALAR_TYPE type){
        return static_cast<SR_TYPE>((type >> 4) << 4);
    }

    u8 getTextureChannelCount(SR_TEXTURE_FORMAT format){
        return format >> 4;
    }

    SR_TYPE getTextureDataType(SR_TEXTURE_FORMAT format){
        return static_cast<SR_TYPE>(format << 4);
    }

    u8 getBytesPerPixel(SR_TEXTURE_FORMAT format){
        auto channelCount = getTextureChannelCount(format);
        auto dataType = getTextureDataType(format);
        return channelCount * getTypeSize(dataType);
    }

}
