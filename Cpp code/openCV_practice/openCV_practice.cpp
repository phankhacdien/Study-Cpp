#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>


using namespace cv;
using namespace std;


int isImage(Mat img)
{
	if (img.empty())
	{
		cout << "Image cannot found!!!";
		cin.get();		// wait forr any key press
		return(-1);
	}
}


int main()
{
	// Read the image from File.
	Mat img = imread("D:/Sherlock/Image/dien4x6.jpg");

	isImage(img);

	// Display identified image.
	String windowMame_1 = "The image";			// Name of the window.
	namedWindow(windowMame_1);					// Create a window
	imshow(windowMame_1, img);					// Show our image inside the created window
	waitKey(0);									// Wait for any keystroke in th window.
	destroyWindow(windowMame_1);

	/*=======================================================================================================================*/

	// Display new blank image.
	String windowName_2 = "New blank image";	// Define new name for second window.
	namedWindow(windowName_2);
	Mat img_2(400, 400, CV_8UC3, Scalar(100, 100, 250));
	imshow(windowName_2, img_2);
	waitKey(0);
	destroyWindow(windowName_2);

	// Save new blank image.
	bool isSuccess = imwrite("D:/Sherlock/Image/new image.jpg", img_2);		// Write image to file as JPEG
	if (isSuccess = false)
	{
		cout << "Failed to save image";
		cin.get();															// Wait for key press.
		return -1;
	}
	cout << "Image was save successfully!";
	String newimage_windowName = "The new image";		// Name of the window.
	namedWindow(newimage_windowName);					// Create new window.
	imshow(newimage_windowName, img_2);					// Show image inside created window.
	waitKey(0);											// Wait for any keystroke in th window.
	destroyWindow(newimage_windowName);					// close window.

	/*=======================================================================================================================*/

	// Change brightness of image and video
	Mat img_3 = imread("D:/Sherlock/Image/dien4x6.jpg");

	if (img_3.empty())
	{
		cout << "Cannot found image!!!";
		cin.get();
		return -1;
	}

	Mat imageBrightnessHigh50;
	img_3.convertTo(imageBrightnessHigh50, -1, 1, 50);

	return 0;

}