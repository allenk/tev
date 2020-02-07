// This file was developed by Thomas Müller <thomas94@gmx.net>.
// It is published under the BSD 3-Clause License within the LICENSE file.

#include <tev/imageio/StbiHdrImageSaver.h>

#include <stb_image_write.h>

#include <ostream>
#include <vector>

using namespace Eigen;
using namespace filesystem;
using namespace std;

TEV_NAMESPACE_BEGIN

void StbiHdrImageSaver::save(ostream& oStream, const path& path, const vector<float>& data, const Vector2i& imageSize, int nChannels) const {
    static const auto stbiOfstreamWrite = [](void* context, void* data, int size) {
        reinterpret_cast<ostream*>(context)->write(reinterpret_cast<char*>(data), size);
    };

    stbi_write_hdr_to_func(stbiOfstreamWrite, &oStream, imageSize.x(), imageSize.y(), nChannels, data.data());
}

TEV_NAMESPACE_END