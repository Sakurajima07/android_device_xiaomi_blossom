#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/non_ab_device.mk)

# Inherit from device makefile.
$(call inherit-product, device/xiaomi/blossom/device.mk)

# Inherit some common lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Maintainer Name
ORION_MAINTAINER := Qbhi

# Enable/Disable GApps
ORION_GAPPS := false

# Enable/Disable Blur
TARGET_ENABLE_BLUR := true

# Bootanimation Resolution
TARGET_BOOT_ANIMATION_RES := 1080

# Bootanimation for Pixel Devices
TARGET_PIXEL_BOOT_ANIMATION_RES := 1080

PRODUCT_NAME := lineage_blossom
PRODUCT_DEVICE := blossom
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := Redmi

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi
