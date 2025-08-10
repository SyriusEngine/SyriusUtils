#pragma once

#include <SyriusUtils/DevUtils/MacroExpansion.hpp>
#include <fmt/format.h>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <exception>
#include <vector>
#include <type_traits>

#define SR_ENUM_PP_MAP(macro, data, ...)                         \
    SR_ENUM_ID(SR_ENUM_APPLY(SR_ENUM_PP_MAP_VAR_COUNT, \
                                       SR_ENUM_PP_COUNT(__VA_ARGS__))(macro, data, __VA_ARGS__))

#define SR_ENUM_PP_MAP_VAR_COUNT(count) SR_ENUM_M##count

#define SR_ENUM_APPLY(macro, ...) SR_ENUM_ID(macro(__VA_ARGS__))

#define SR_ENUM_ID(x) x

#define SR_ENUM_M1(m, d, x) m(d, 0, x)
#define SR_ENUM_M2(m, d, x, ...) m(d, 1, x) SR_ENUM_ID(SR_ENUM_M1(m, d, __VA_ARGS__))
#define SR_ENUM_M3(m, d, x, ...) m(d, 2, x) SR_ENUM_ID(SR_ENUM_M2(m, d, __VA_ARGS__))
#define SR_ENUM_M4(m, d, x, ...) m(d, 3, x) SR_ENUM_ID(SR_ENUM_M3(m, d, __VA_ARGS__))
#define SR_ENUM_M5(m, d, x, ...) m(d, 4, x) SR_ENUM_ID(SR_ENUM_M4(m, d, __VA_ARGS__))
#define SR_ENUM_M6(m, d, x, ...) m(d, 5, x) SR_ENUM_ID(SR_ENUM_M5(m, d, __VA_ARGS__))
#define SR_ENUM_M7(m, d, x, ...) m(d, 6, x) SR_ENUM_ID(SR_ENUM_M6(m, d, __VA_ARGS__))
#define SR_ENUM_M8(m, d, x, ...) m(d, 7, x) SR_ENUM_ID(SR_ENUM_M7(m, d, __VA_ARGS__))
#define SR_ENUM_M9(m, d, x, ...) m(d, 8, x) SR_ENUM_ID(SR_ENUM_M8(m, d, __VA_ARGS__))
#define SR_ENUM_M10(m, d, x, ...) m(d, 9, x) SR_ENUM_ID(SR_ENUM_M9(m, d, __VA_ARGS__))
#define SR_ENUM_M11(m, d, x, ...) m(d, 10, x) SR_ENUM_ID(SR_ENUM_M10(m, d, __VA_ARGS__))
#define SR_ENUM_M12(m, d, x, ...) m(d, 11, x) SR_ENUM_ID(SR_ENUM_M11(m, d, __VA_ARGS__))
#define SR_ENUM_M13(m, d, x, ...) m(d, 12, x) SR_ENUM_ID(SR_ENUM_M12(m, d, __VA_ARGS__))
#define SR_ENUM_M14(m, d, x, ...) m(d, 13, x) SR_ENUM_ID(SR_ENUM_M13(m, d, __VA_ARGS__))
#define SR_ENUM_M15(m, d, x, ...) m(d, 14, x) SR_ENUM_ID(SR_ENUM_M14(m, d, __VA_ARGS__))
#define SR_ENUM_M16(m, d, x, ...) m(d, 15, x) SR_ENUM_ID(SR_ENUM_M15(m, d, __VA_ARGS__))
#define SR_ENUM_M17(m, d, x, ...) m(d, 16, x) SR_ENUM_ID(SR_ENUM_M16(m, d, __VA_ARGS__))
#define SR_ENUM_M18(m, d, x, ...) m(d, 17, x) SR_ENUM_ID(SR_ENUM_M17(m, d, __VA_ARGS__))
#define SR_ENUM_M19(m, d, x, ...) m(d, 18, x) SR_ENUM_ID(SR_ENUM_M18(m, d, __VA_ARGS__))
#define SR_ENUM_M20(m, d, x, ...) m(d, 19, x) SR_ENUM_ID(SR_ENUM_M19(m, d, __VA_ARGS__))
#define SR_ENUM_M21(m, d, x, ...) m(d, 20, x) SR_ENUM_ID(SR_ENUM_M20(m, d, __VA_ARGS__))
#define SR_ENUM_M22(m, d, x, ...) m(d, 21, x) SR_ENUM_ID(SR_ENUM_M21(m, d, __VA_ARGS__))
#define SR_ENUM_M23(m, d, x, ...) m(d, 22, x) SR_ENUM_ID(SR_ENUM_M22(m, d, __VA_ARGS__))
#define SR_ENUM_M24(m, d, x, ...) m(d, 23, x) SR_ENUM_ID(SR_ENUM_M23(m, d, __VA_ARGS__))
#define SR_ENUM_M25(m, d, x, ...) m(d, 24, x) SR_ENUM_ID(SR_ENUM_M24(m, d, __VA_ARGS__))
#define SR_ENUM_M26(m, d, x, ...) m(d, 25, x) SR_ENUM_ID(SR_ENUM_M25(m, d, __VA_ARGS__))
#define SR_ENUM_M27(m, d, x, ...) m(d, 26, x) SR_ENUM_ID(SR_ENUM_M26(m, d, __VA_ARGS__))
#define SR_ENUM_M28(m, d, x, ...) m(d, 27, x) SR_ENUM_ID(SR_ENUM_M27(m, d, __VA_ARGS__))
#define SR_ENUM_M29(m, d, x, ...) m(d, 28, x) SR_ENUM_ID(SR_ENUM_M28(m, d, __VA_ARGS__))
#define SR_ENUM_M30(m, d, x, ...) m(d, 29, x) SR_ENUM_ID(SR_ENUM_M29(m, d, __VA_ARGS__))
#define SR_ENUM_M31(m, d, x, ...) m(d, 30, x) SR_ENUM_ID(SR_ENUM_M30(m, d, __VA_ARGS__))
#define SR_ENUM_M32(m, d, x, ...) m(d, 31, x) SR_ENUM_ID(SR_ENUM_M31(m, d, __VA_ARGS__))
#define SR_ENUM_M33(m, d, x, ...) m(d, 32, x) SR_ENUM_ID(SR_ENUM_M32(m, d, __VA_ARGS__))
#define SR_ENUM_M34(m, d, x, ...) m(d, 33, x) SR_ENUM_ID(SR_ENUM_M33(m, d, __VA_ARGS__))
#define SR_ENUM_M35(m, d, x, ...) m(d, 34, x) SR_ENUM_ID(SR_ENUM_M34(m, d, __VA_ARGS__))
#define SR_ENUM_M36(m, d, x, ...) m(d, 35, x) SR_ENUM_ID(SR_ENUM_M35(m, d, __VA_ARGS__))
#define SR_ENUM_M37(m, d, x, ...) m(d, 36, x) SR_ENUM_ID(SR_ENUM_M36(m, d, __VA_ARGS__))
#define SR_ENUM_M38(m, d, x, ...) m(d, 37, x) SR_ENUM_ID(SR_ENUM_M37(m, d, __VA_ARGS__))
#define SR_ENUM_M39(m, d, x, ...) m(d, 38, x) SR_ENUM_ID(SR_ENUM_M38(m, d, __VA_ARGS__))
#define SR_ENUM_M40(m, d, x, ...) m(d, 39, x) SR_ENUM_ID(SR_ENUM_M39(m, d, __VA_ARGS__))
#define SR_ENUM_M41(m, d, x, ...) m(d, 40, x) SR_ENUM_ID(SR_ENUM_M40(m, d, __VA_ARGS__))
#define SR_ENUM_M42(m, d, x, ...) m(d, 41, x) SR_ENUM_ID(SR_ENUM_M41(m, d, __VA_ARGS__))
#define SR_ENUM_M43(m, d, x, ...) m(d, 42, x) SR_ENUM_ID(SR_ENUM_M42(m, d, __VA_ARGS__))
#define SR_ENUM_M44(m, d, x, ...) m(d, 43, x) SR_ENUM_ID(SR_ENUM_M43(m, d, __VA_ARGS__))
#define SR_ENUM_M45(m, d, x, ...) m(d, 44, x) SR_ENUM_ID(SR_ENUM_M44(m, d, __VA_ARGS__))
#define SR_ENUM_M46(m, d, x, ...) m(d, 45, x) SR_ENUM_ID(SR_ENUM_M45(m, d, __VA_ARGS__))
#define SR_ENUM_M47(m, d, x, ...) m(d, 46, x) SR_ENUM_ID(SR_ENUM_M46(m, d, __VA_ARGS__))
#define SR_ENUM_M48(m, d, x, ...) m(d, 47, x) SR_ENUM_ID(SR_ENUM_M47(m, d, __VA_ARGS__))
#define SR_ENUM_M49(m, d, x, ...) m(d, 48, x) SR_ENUM_ID(SR_ENUM_M48(m, d, __VA_ARGS__))
#define SR_ENUM_M50(m, d, x, ...) m(d, 49, x) SR_ENUM_ID(SR_ENUM_M49(m, d, __VA_ARGS__))
#define SR_ENUM_M51(m, d, x, ...) m(d, 50, x) SR_ENUM_ID(SR_ENUM_M50(m, d, __VA_ARGS__))
#define SR_ENUM_M52(m, d, x, ...) m(d, 51, x) SR_ENUM_ID(SR_ENUM_M51(m, d, __VA_ARGS__))
#define SR_ENUM_M53(m, d, x, ...) m(d, 52, x) SR_ENUM_ID(SR_ENUM_M52(m, d, __VA_ARGS__))
#define SR_ENUM_M54(m, d, x, ...) m(d, 53, x) SR_ENUM_ID(SR_ENUM_M53(m, d, __VA_ARGS__))
#define SR_ENUM_M55(m, d, x, ...) m(d, 54, x) SR_ENUM_ID(SR_ENUM_M54(m, d, __VA_ARGS__))
#define SR_ENUM_M56(m, d, x, ...) m(d, 55, x) SR_ENUM_ID(SR_ENUM_M55(m, d, __VA_ARGS__))
#define SR_ENUM_M57(m, d, x, ...) m(d, 56, x) SR_ENUM_ID(SR_ENUM_M56(m, d, __VA_ARGS__))
#define SR_ENUM_M58(m, d, x, ...) m(d, 57, x) SR_ENUM_ID(SR_ENUM_M57(m, d, __VA_ARGS__))
#define SR_ENUM_M59(m, d, x, ...) m(d, 58, x) SR_ENUM_ID(SR_ENUM_M58(m, d, __VA_ARGS__))
#define SR_ENUM_M60(m, d, x, ...) m(d, 59, x) SR_ENUM_ID(SR_ENUM_M59(m, d, __VA_ARGS__))
#define SR_ENUM_M61(m, d, x, ...) m(d, 60, x) SR_ENUM_ID(SR_ENUM_M60(m, d, __VA_ARGS__))
#define SR_ENUM_M62(m, d, x, ...) m(d, 61, x) SR_ENUM_ID(SR_ENUM_M61(m, d, __VA_ARGS__))
#define SR_ENUM_M63(m, d, x, ...) m(d, 62, x) SR_ENUM_ID(SR_ENUM_M62(m, d, __VA_ARGS__))
#define SR_ENUM_M64(m, d, x, ...) m(d, 63, x) SR_ENUM_ID(SR_ENUM_M63(m, d, __VA_ARGS__))

#define SR_ENUM_PP_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, count, ...) count

#define SR_ENUM_PP_COUNT(...)                                                                                     \
    SR_ENUM_ID(SR_ENUM_PP_COUNT_IMPL(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

template<typename T>
struct is_sr_enum: std::false_type {};

namespace Syrius::Detail {

    /** Get intrinsic value of an (Enum::value) by taking advantage of
     * C-conversion's parentheses priority
     */
    template<typename EnumType>
    struct _eat_assign {
        explicit constexpr _eat_assign(EnumType value) : _value(value) {}

        template<typename Any>
        constexpr const _eat_assign &operator=(Any) const
        {
            return *this;
        }

        explicit constexpr operator EnumType() const { return _value; }

    private:
        EnumType _value;
    };

    inline std::string getEnumValue(const std::string& full_expansion) {
        std::string_view view = full_expansion;

        // Find the position of '='
        auto pos = view.find('=');
        if (pos != std::string_view::npos) {
            // Trim whitespace before '='
            view = view.substr(0, pos);

            // Trim trailing whitespace
            size_t end = view.find_last_not_of(" \t");
            if (end != std::string_view::npos) {
                view = view.substr(0, end + 1);
            }
        }

        return std::string(view);
    }

}

#define SR_ENUM_VALUE_COUNT_NAME _ValueCount

#define SR_ENUM_ADD_ENTRY(EnumType, idx, expression) expression,
#define SR_ENUM_ADD_VALUE(EnumType, idx, expression) \
    (EnumType)((Syrius::Detail::_eat_assign<EnumType>)EnumType::expression),
#define SR_ENUM_VALUE_STRING(EnumType, idx, expression) \
    #expression,

#define SR_ENUM_VALUE_ARRAY_NAME _Values
#define SR_ENUM_RAW_NAMES_ARRAY_NAME _RawNames
#define SR_ENUM_MAP_VALUE_TO_STR _ValueToStr
#define SR_ENUM_MAP_STR_TO_VALUE _StrToValue

/**
 * @brief Macro to generate an enum with fromString and toString function. This code is heavily inspired by
 *        BETTER_ENUM.
 * @param Name
 * @param Type
 */
#define SR_ENUM(Name, Type, ...) \
    typedef enum Name: Type { \
        SR_ENUM_ID(SR_ENUM_PP_MAP(SR_ENUM_ADD_ENTRY, Name, __VA_ARGS__)) \
    } Name; \
    template<>\
    struct is_sr_enum<Name>: std::true_type {}; \
    namespace Name##_detail{ \
        constexpr std::size_t SR_ENUM_VALUE_COUNT_NAME = VA_COUNT(__VA_ARGS__); \
        constexpr Name SR_ENUM_VALUE_ARRAY_NAME[] = { \
            SR_ENUM_ID(SR_ENUM_PP_MAP(SR_ENUM_ADD_VALUE, Name, __VA_ARGS__)) \
        };\
        static std::vector<std::string> SR_ENUM_RAW_NAMES_ARRAY_NAME = { \
            SR_ENUM_ID(SR_ENUM_PP_MAP(SR_ENUM_VALUE_STRING, Name, __VA_ARGS__)) \
        }; \
        static bool Name##_StructuresGenerated = false; \
        std::unordered_map<Name, std::string> SR_ENUM_MAP_VALUE_TO_STR; \
        std::unordered_map<std::string, Name> SR_ENUM_MAP_STR_TO_VALUE; \
        static void generateStructures(){ \
            for (std::size_t idx = 0; idx < SR_ENUM_VALUE_COUNT_NAME; idx++){ \
                Name value = SR_ENUM_VALUE_ARRAY_NAME[idx]; \
                std::string value_str = Syrius::Detail::getEnumValue(SR_ENUM_RAW_NAMES_ARRAY_NAME[idx]); \
                SR_ENUM_MAP_VALUE_TO_STR.insert({value, value_str}); \
                SR_ENUM_MAP_STR_TO_VALUE.insert({value_str, value}); \
            } \
            Name##_StructuresGenerated = true; \
        } \
    } \
    inline std::string toString(Name value){ \
        if (!Name##_detail::Name##_StructuresGenerated){ \
            Name##_detail::generateStructures(); \
        } \
        return Name##_detail::SR_ENUM_MAP_VALUE_TO_STR.at(value); \
    } \
    inline Name fromString(const std::string& value){ \
        if (!Name##_detail::Name##_StructuresGenerated){ \
            Name##_detail::generateStructures(); \
        } \
        auto it = Name##_detail::SR_ENUM_MAP_STR_TO_VALUE.find(value); \
        if (it == Name##_detail::SR_ENUM_MAP_STR_TO_VALUE.end()){ \
            const std::string msg = "Cannot convert: " + value + " to enum of type: " + std::string(#Name); \
            throw std::runtime_error(msg); \
        } \
        return it->second; \
    } \
    template<> \
    struct fmt::formatter<Name>{\
        constexpr auto parse(fmt::format_parse_context& ctx) -> decltype(ctx.begin()) { \
            return ctx.begin(); \
        } \
        template <typename FormatContext> \
        auto format(const Name value, FormatContext& ctx) const -> decltype(ctx.out()) { \
            return fmt::format_to(ctx.out(), "{}", toString(value)); \
        } \
    };

