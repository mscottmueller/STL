// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <assert.h>
#include <functional>
#include <sstream>
#include <string>

using namespace std;

struct A {
    string meow(int i) {
        ostringstream oss;

        oss << "A::meow(" << i + 9 * 9 * 9 << ")";

        return oss.str();
    }
};

int main() {
    A a;

    auto f = bind(&A::meow, ref(a), 1000);

    assert(f() == "A::meow(1729)");
}
