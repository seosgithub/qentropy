#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

int main() {
  /* Start the webcam capture */
  CvCapture *cap = cvCaptureFromCAM(0);
  if (cap == NULL) {
    fprintf(stderr, "Couldn't open the webcam\n");
    exit(EXIT_FAILURE);
  }

  /* Start the generation */
  while (1) {
    /* Get a frame from the webcam */
    IplImage *frame = cvQueryFrame(cap);

    unsigned int total_space = frame->width*frame->height;
    /* XOR each pixel togeather, shift by a random amount too so we don't end up in low or extremes */
    unsigned char res = 0;
    for (int i = 0; i < frame->width*frame->height; ++i) {
      res = (res ^ frame->imageData[i] << (res % 8));
    }

    /* Output result */
    printf("%u\n", res);
    fflush(stdout);
  }

  return 0;
}
