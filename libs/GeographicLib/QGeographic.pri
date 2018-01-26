# -------------------------------------------------
# QGroundControl - Micro Air Vehicle Groundstation
# Please see our website at <http://qgroundcontrol.org>
# Maintainer:
# Lorenz Meier <lm@inf.ethz.ch>
# (c) 2009-2015 QGroundControl Developers
#
# This file is part of the open groundstation project
# QGroundControl is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# QGroundControl is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with QGroundControl. If not, see <http://www.gnu.org/licenses/>.
#
# Author: Gus Grubba <mavlink@grubba.com>
# -------------------------------------------------

#
#-- Depends on gstreamer, which can be found at: http://gstreamer.freedesktop.org/download/
#


INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

HEADERS += \
            $$PWD/include/GeographicLib/Accumulator.hpp \
            $$PWD/include/GeographicLib/AlbersEqualArea.hpp \
            $$PWD/include/GeographicLib/AzimuthalEquidistant.hpp \
            $$PWD/include/GeographicLib/CassiniSoldner.hpp \
            $$PWD/include/GeographicLib/CircularEngine.hpp \
            $$PWD/include/GeographicLib/Constants.hpp \
            $$PWD/include/GeographicLib/DMS.hpp \
            $$PWD/include/GeographicLib/Ellipsoid.hpp \
            $$PWD/include/GeographicLib/EllipticFunction.hpp \
            $$PWD/include/GeographicLib/GARS.hpp \
            $$PWD/include/GeographicLib/GeoCoords.hpp \
            $$PWD/include/GeographicLib/Geocentric.hpp \
            $$PWD/include/GeographicLib/Geodesic.hpp \
            $$PWD/include/GeographicLib/GeodesicExact.hpp \
            $$PWD/include/GeographicLib/GeodesicLine.hpp \
            $$PWD/include/GeographicLib/GeodesicLineExact.hpp \
            $$PWD/include/GeographicLib/Geohash.hpp \
            $$PWD/include/GeographicLib/Geoid.hpp \
            $$PWD/include/GeographicLib/Georef.hpp \
            $$PWD/include/GeographicLib/Gnomonic.hpp \
            $$PWD/include/GeographicLib/GravityCircle.hpp \
            $$PWD/include/GeographicLib/GravityModel.hpp \
            $$PWD/include/GeographicLib/LambertConformalConic.hpp \
            $$PWD/include/GeographicLib/LocalCartesian.hpp \
            $$PWD/include/GeographicLib/MGRS.hpp \
            $$PWD/include/GeographicLib/MagneticCircle.hpp \
            $$PWD/include/GeographicLib/MagneticModel.hpp \
            $$PWD/include/GeographicLib/Math.hpp \
            $$PWD/include/GeographicLib/NormalGravity.hpp \
            $$PWD/include/GeographicLib/OSGB.hpp \
            $$PWD/include/GeographicLib/PolarStereographic.hpp \
            $$PWD/include/GeographicLib/PolygonArea.hpp \
            $$PWD/include/GeographicLib/Rhumb.hpp \
            $$PWD/include/GeographicLib/SphericalEngine.hpp \
            $$PWD/include/GeographicLib/SphericalHarmonic.hpp \
            $$PWD/include/GeographicLib/SphericalHarmonic1.hpp \
            $$PWD/include/GeographicLib/SphericalHarmonic2.hpp \
            $$PWD/include/GeographicLib/TransverseMercator.hpp \
            $$PWD/include/GeographicLib/TransverseMercatorExact.hpp \
            $$PWD/include/GeographicLib/UTMUPS.hpp \
            $$PWD/include/GeographicLib/Utility.hpp \
            $$PWD/include/GeographicLib/Config.h

SOURCES += \
            $$PWD/src/Accumulator.cpp \
            $$PWD/src/AlbersEqualArea.cpp \
            $$PWD/src/AzimuthalEquidistant.cpp \
            $$PWD/src/CassiniSoldner.cpp \
            $$PWD/src/CircularEngine.cpp \
            $$PWD/src/DMS.cpp \
            $$PWD/src/Ellipsoid.cpp \
            $$PWD/src/EllipticFunction.cpp \
            $$PWD/src/GARS.cpp \
            $$PWD/src/GeoCoords.cpp \
            $$PWD/src/Geocentric.cpp \
            $$PWD/src/Geodesic.cpp \
            $$PWD/src/GeodesicExact.cpp \
            $$PWD/src/GeodesicExactC4.cpp \
            $$PWD/src/GeodesicLine.cpp \
            $$PWD/src/GeodesicLineExact.cpp \
            $$PWD/src/Geohash.cpp \
            $$PWD/src/Geoid.cpp \
            $$PWD/src/Georef.cpp \
            $$PWD/src/Gnomonic.cpp \
            $$PWD/src/GravityCircle.cpp \
            $$PWD/src/GravityModel.cpp \
            $$PWD/src/LambertConformalConic.cpp \
            $$PWD/src/LocalCartesian.cpp \
            $$PWD/src/MGRS.cpp \
            $$PWD/src/MagneticCircle.cpp \
            $$PWD/src/MagneticModel.cpp \
            $$PWD/src/Math.cpp \
            $$PWD/src/NormalGravity.cpp \
            $$PWD/src/OSGB.cpp \
            $$PWD/src/PolarStereographic.cpp \
            $$PWD/src/PolygonArea.cpp \
            $$PWD/src/Rhumb.cpp \
            $$PWD/src/SphericalEngine.cpp \
            $$PWD/src/TransverseMercator.cpp \
            $$PWD/src/TransverseMercatorExact.cpp \
            $$PWD/src/UTMUPS.cpp \
            $$PWD/src/Utility.cpp \

