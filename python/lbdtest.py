import numpy as np
import cv2
import pylbd

def pylbd_test1():
    img1 = cv2.imread('../test_imgs/000000.png')
    img2 = cv2.imread('../test_imgs/000001.png')
    n_oct = 1
    factor = 1.2
#    lines1 = pylbd.detect_edlines(img1, n_oct, factor)
#    lines2 = pylbd.detect_edlines(img2, n_oct, factor)
    descs1, lines1 = pylbd.detect_and_describe(img1, n_oct, factor)
    # descs11 = pylbd.describe_with_lbd(img1, lines1, n_oct, factor)
    descs2, lines2 = pylbd.detect_and_describe(img2, n_oct, factor)

    matches = pylbd.match_lbd_descriptors(descs1, descs2)

    debug_img = pylbd.visualize_line_matching(img1, lines1, img2, lines2, matches, True)
    cv2.imshow("a", debug_img)
    cv2.waitKey()
    print('-')

pylbd_test1()
