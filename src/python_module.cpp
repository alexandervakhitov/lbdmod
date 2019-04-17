#define PY_ARRAY_UNIQUE_SYMBOL pbcvt_ARRAY_API

#include <boost/python.hpp>
#include "pyboostcvconverter/pyboostcvconverter.hpp"
#include "lbd_mod_funcs.h"
#include "dataconv.h"

namespace pylbd {

    using namespace boost::python;

/**
 * @brief Example function. Basic inner matrix product using explicit matrix conversion.
 * @param left left-hand matrix operand (NdArray required)
 * @param right right-hand matrix operand (NdArray required)
 * @return an NdArray representing the dot-product of the left and right operands
 */
//void DetectEDLines(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>* detections_p)
    cv::Mat detect_edlines(cv::Mat image, int n_octaves, double factor)
    {
        std::vector<cv::line_descriptor::KeyLine> detections;
        DetectEDLines(image, n_octaves, factor, &detections);
        cv::Mat lines_data = ConvertKeyLines2Mat(detections);
        return lines_data;
    }

    boost::python::tuple detect_and_describe(cv::Mat image, int n_octaves, double factor)
    {
        std::vector<cv::line_descriptor::KeyLine> detections;
//        std::cout << "lines converted " << detections.size() << std::endl;
        cv::Mat descs;
        DetectComputeLBD(image, n_octaves, factor, &detections, &descs);
        cv::Mat lines_data = ConvertKeyLines2Mat(detections);
//        std::vector<cv::Mat> result;
//        result.push_back(descs);
//        result.push_back(lines_data);
//        std::cout << "lbd computed" << std::endl;
        return boost::python::make_tuple(descs, lines_data);
    }

    cv::Mat describe_with_lbd(cv::Mat image, cv::Mat detsMat, int n_octaves, double factor)
    {
//        std::cout << " method started " << std::endl;
        std::vector<cv::line_descriptor::KeyLine> detections = ConvertMat2KeyLines(detsMat);
//        std::cout << "lines converted " << detections.size() << std::endl;
        cv::Mat descs;
        ComputeLBD(image, n_octaves, factor, detections, &descs);
//        std::cout << "lbd computed" << std::endl;
        return descs;
    }


    cv::Mat match_lbd_descriptors(cv::Mat desc1, cv::Mat desc2)
    {
        std::vector<cv::DMatch> matchingVec;
        MatchLBD(desc1, desc2, &matchingVec);
        cv::Mat matchingMat = ConvertMatches2Mat(matchingVec);
        return matchingMat;
    }

    cv::Mat visualize_line_matching(cv::Mat image1, cv::Mat lines1, cv::Mat image2, cv::Mat lines2, cv::Mat matches, bool is_vertical)
    {
        //cv::line_descriptor::drawLineMatches(imageColor2, lines2, imageColor, lines, matches, debugMatchingImg, true);

        std::vector<cv::line_descriptor::KeyLine> keyLines1 = ConvertMat2KeyLines(lines1);
        std::vector<cv::line_descriptor::KeyLine> keyLines2 = ConvertMat2KeyLines(lines2);
        std::vector<cv::DMatch> matchesVec = ConvertMat2Matches(matches);
        cv::Mat debugMatchingImg;
//        std::cout << " before drawing " << keyLines1.size() << " " << keyLines2.size() << " " << matchesVec.size() << " " << matches.rows << " " << matches.cols << std::endl;
        cv::line_descriptor::drawLineMatches(image1, keyLines1, image2, keyLines2, matchesVec, debugMatchingImg, is_vertical);
        return debugMatchingImg;
    }


#if (PY_VERSION_HEX >= 0x03000000)

    static void *init_ar() {
#else
        static void init_ar(){
#endif
        Py_Initialize();

        import_array();
        return NUMPY_IMPORT_ARRAY_RETVAL;
    }

    BOOST_PYTHON_MODULE (pylbd) {
        //using namespace XM;
        init_ar();

        //initialize converters
        to_python_converter<cv::Mat,pbcvt::matToNDArrayBoostConverter>();
        pbcvt::matFromNDArrayBoostConverter();

        //expose module-level functions
        def("detect_edlines", detect_edlines);
        def("detect_and_describe", detect_and_describe);
        def("describe_with_lbd", describe_with_lbd);
        def("match_lbd_descriptors", match_lbd_descriptors);
        def("visualize_line_matching", visualize_line_matching);

		//from PEP8 (https://www.python.org/dev/peps/pep-0008/?#prescriptive-naming-conventions)
        //"Function names should be lowercase, with words separated by underscores as necessary to improve readability."
//        def("increment_elements_by_one", increment_elements_by_one);
    }

} //end namespace pylbd
