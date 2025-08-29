// enum_bitmask_utils.hpp
#pragma once
#include <type_traits>
#include <string>
#include <string_view>
#include <array>
#include <optional>
#include <cstddef>

// -----------------------------
// Opt-in switch for an enum type
// -----------------------------

template <class E>
struct enable_bitmask_operators : std::false_type {};

// Helper: C++23 has std::to_underlying. Provide a backport:
template <class E>
constexpr auto to_underlying(E e) noexcept {
    return static_cast<std::underlying_type_t<E>>(e);
}

// Concept: enabled enum
template <class E>
concept bitmask_enum =
std::is_enum_v<E> && enable_bitmask_operators<E>::value;

// -----------------------------
// Core bitwise operators
// -----------------------------
template <bitmask_enum E>
[[nodiscard]] constexpr E operator|(E lhs, E rhs) noexcept 
{
    using U = std::underlying_type_t<E>;
    return static_cast<E>(static_cast<U>(lhs) | static_cast<U>(rhs));
}

template <bitmask_enum E>
[[nodiscard]] constexpr E operator&(E lhs, E rhs) noexcept 
{
    using U = std::underlying_type_t<E>;
    return static_cast<E>(static_cast<U>(lhs) & static_cast<U>(rhs));
}

template <bitmask_enum E>
[[nodiscard]] constexpr E operator^(E lhs, E rhs) noexcept 
{
    using U = std::underlying_type_t<E>;
    return static_cast<E>(static_cast<U>(lhs) ^ static_cast<U>(rhs));
}

template <bitmask_enum E>
[[nodiscard]] constexpr E operator~(E v) noexcept 
{
    using U = std::underlying_type_t<E>;
    return static_cast<E>(~static_cast<U>(v));
}

template <bitmask_enum E>
constexpr E& operator|=(E& lhs, E rhs) noexcept 
{ 
    return lhs = (lhs | rhs); 
}

template <bitmask_enum E>
constexpr E& operator&=(E& lhs, E rhs) noexcept 
{ 
    return lhs = (lhs & rhs); 
}

template <bitmask_enum E>
constexpr E& operator^=(E& lhs, E rhs) noexcept 
{ 
    return lhs = (lhs ^ rhs); 
}

// -----------------------------
// Helpers for flags
// -----------------------------
template <bitmask_enum E>
[[nodiscard]] constexpr bool has_flag(E value, E flag) noexcept 
{
    using U = std::underlying_type_t<E>;
    return (static_cast<U>(value) & static_cast<U>(flag)) == static_cast<U>(flag);
}

template <bitmask_enum E, class... Flags>
[[nodiscard]] constexpr bool has_all(E value, Flags... flags) noexcept 
{
    return ((has_flag(value, flags)) && ...);
}

template <bitmask_enum E, class... Flags>
[[nodiscard]] constexpr bool has_any(E value, Flags... flags) noexcept 
{
    return ((static_cast<bool>(value & flags)) || ...);
}

template <bitmask_enum E>
constexpr void set_flag(E& value, E flag) noexcept 
{ 
    value |= flag; 
}

template <bitmask_enum E>
constexpr void clear_flag(E& value, E flag) noexcept 
{
    value &= static_cast<E>(~to_underlying(flag));
}

template <bitmask_enum E>
constexpr void toggle_flag(E& value, E flag) noexcept 
{ 
    value ^= flag; 
}

template <bitmask_enum E>
[[nodiscard]] constexpr bool none(E value) noexcept 
{
    using U = std::underlying_type_t<E>;
    return static_cast<U>(value) == 0;
}

template <bitmask_enum E>
[[nodiscard]] constexpr bool any(E value) noexcept 
{ 
    return !none(value); 
}

