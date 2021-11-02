//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Developed by Minigraph
//
// Author:  James Stanard 
//

#pragma once

#include "pch.h"
#include <cstddef>
#include <vector>
#include <string>
#include <ppl.h>

namespace Playground::Utility
{
    using namespace concurrency;

    typedef std::shared_ptr<std::vector<std::byte>> ByteArray;
    extern ByteArray NullFile;

    // Reads the entire contents of a binary file.  If the file with the same name except with an additional
    // ".gz" suffix exists, it will be loaded and decompressed instead.
    // This operation blocks until the entire file is read.
    ByteArray ReadFileSync(const std::wstring& fileName);

    // Same as previous except that it does not block but instead returns a task.
    task<ByteArray> ReadFileAsync(const std::wstring& fileName);

} // namespace Utility
