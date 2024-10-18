soon

<!---
// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdint>
enum class Permission : uint8_t
{
    Read = 0,
    Write,
    Execute,
};

Permission initWithEnumeration{Permission::Read};
Permission initForPreCpp17{static_cast<Permission>(0)};
Permission initForCpp17{0};
Permission initWithType = Permission{0};
// the following would _not_ compile:
// Permission initWithEqual = 0;
// Permission initWithEqualAndBraces = {0};
int main() {}
--->
