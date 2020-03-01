#include <libusb.h>

#include "../../utils/common_types.h"

#define DPF_BYTE_PRE_PIXEL 2

#define DPF_ERROR_DEVICE_NOT_SUPPORTED 1

typedef struct dpf_device dpf_device;

//dpf_device *dpf_init(struct libusb_device_handle *descriptor);

int dpf_device_open(libusb_device *device, dpf_device **new_device);

// Ask the screen it's dimension
int dpf_device_acquire_dimensions(dpf_device *device);

// Set back-light brightness
int dpf_device_set_brightness(dpf_device *device, unsigned int brightness);

unsigned int dpf_device_get_brightness(dpf_device *device);

int dpf_device_bulk_transfer(dpf_device *device, const unsigned char *buffer, RectTuple *rectTuple);

int dpf_device_flush(dpf_device *device, RectTuple *rectTuple);

// Properties
unsigned int dpf_device_screen_width(dpf_device *device);

unsigned int dpf_device_screen_height(dpf_device *device);

// Device buffer
unsigned long dpf_device_get_buffer_size(dpf_device *device);

unsigned char *dpf_device_get_buffer(dpf_device *device);

void dpf_destroy(dpf_device *device);