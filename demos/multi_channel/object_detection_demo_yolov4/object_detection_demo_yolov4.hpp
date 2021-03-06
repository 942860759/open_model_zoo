/*
// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once

#include <string>
#include <vector>
#include <gflags/gflags.h>
#include <iostream>

#ifdef _WIN32
#include <os/windows/w_dirent.h>
#else
#include <dirent.h>
#endif

/// @brief message for help argument
static const char help_message[] = "Print a usage message.";

/// @brief message for images argument
static const char image_message[] = "Required. Path to a folder with images or path to an image files: a .ubyte file for LeNet"\
                                    "and a .bmp file for the other networks.";

/// @brief message for plugin_path argument
static const char plugin_path_message[] = "Path to a plugin folder.";

/// @brief message for model argument
static const char model_message[] = "Required. Path to an .xml file with a trained model.";

/// @brief message for assigning cnn calculation to device
static const char target_device_message[] = "Specify the target device to infer on; CPU, GPU, FPGA or MYRIAD is acceptable. " \
                                            "Sample will look for a suitable plugin for device specified (CPU by default)";

/// @brief message for performance counters
static const char performance_counter_message[] = "Enables per-layer performance report";

/// @brief message for top results number
static const char ntop_message[] = "Number of top results (default 10)";

/// @brief message for iterations count
static const char iterations_count_message[] = "Number of iterations (default 1)";

/// @brief message for clDNN custom kernels desc
static const char custom_cldnn_message[] = "Required for clDNN (GPU)-targeted custom kernels."\
                                            "Absolute path to the xml file with the kernels desc.";

/// @brief message for user library argument
static const char custom_cpu_library_message[] = "Required for MKLDNN (CPU)-targeted custom layers." \
                                                 "Absolute path to a shared library with the kernels impl.";

/// @brief message for plugin messages
static const char plugin_message[] = "Enables messages from a plugin";

/// @brief message for threshold of detections
static const char thresh_output_message[] = "Optional. Probability threshold for detections.";

/// @brief message for nms iou thresh
static const char iou_thresh_output_message[] = "Optional. Filtering intersection over union threshold for overlapping boxes.";


/// @brief Define flag for showing help message <br>
DEFINE_bool(h, false, help_message);

/// @brief Define parameter for set image file <br>
/// It is a required parameter
DEFINE_string(i, "", image_message);

/// @brief Define parameter for set model file <br>
/// It is a required parameter
DEFINE_string(m, "", model_message);

/// @brief Define parameter for set path to plugins <br>
DEFINE_string(pp, "", plugin_path_message);

/// @brief device the target device to infer on <br>
DEFINE_string(d, "CPU", target_device_message);

/// @brief Top results number (default 10) <br>
DEFINE_int32(nt, 10, ntop_message);

/// @brief Enable per-layer performance report
DEFINE_bool(pc, false, performance_counter_message);

/// @brief Define parameter for clDNN custom kernels path <br>
/// Default is ./lib
DEFINE_string(c, "", custom_cldnn_message);

/// @brief Absolute path to CPU library with user layers <br>
/// It is a optional parameter
DEFINE_string(l, "", custom_cpu_library_message);

/// @brief Enable plugin messages
DEFINE_bool(p_msg, false, plugin_message);

/// @brief Define parameter for thresh <br>
/// It is a optional parameter
DEFINE_double(t, 0.5, thresh_output_message);

/// @brief Define parameter for nms_iou_thresh <br>
/// It is a optional parameter
DEFINE_double(iou_t, 0.45, iou_thresh_output_message);


/**
* @brief This function show a help message
*/
static void showUsage() {
    std::cout << std::endl;
    std::cout << "object_detection_demo_yolov4 [OPTION]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << std::endl;
    std::cout << "    -h                      " << help_message << std::endl;
    std::cout << "    -i \"<path>\"             " << image_message << std::endl;
    std::cout << "    -m \"<path>\"             " << model_message << std::endl;
    std::cout << "      -l \"<absolute_path>\"    " << custom_cpu_library_message << std::endl;
    std::cout << "          Or" << std::endl;
    std::cout << "      -c \"<absolute_path>\"    " << custom_cldnn_message << std::endl;
    std::cout << "    -pp \"<path>\"            " << plugin_path_message << std::endl;
    std::cout << "    -d \"<device>\"           " << target_device_message << std::endl;
    std::cout << "    -nt \"<integer>\"         " << ntop_message << std::endl;
    std::cout << "    -pc                     " << performance_counter_message << std::endl;
    std::cout << "    -p_msg                  " << plugin_message << std::endl;
    std::cout << "    -t                      " << thresh_output_message << std::endl;
    std::cout << "    -iou_t                  " << iou_thresh_output_message << std::endl;
}
