// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_VSMROUTE_VSM_ROUTE_H_
#define FLATBUFFERS_GENERATED_VSMROUTE_VSM_ROUTE_H_

#include "flatbuffers.h"

namespace vsm {
namespace route {

struct LonLat;

struct RGServiceLink;

struct LinkInfo;

struct GasStationInfo;

struct PositionInfo;

struct AccidentInfo;

struct EVStationInfo;

struct RouteData;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(8) LonLat FLATBUFFERS_FINAL_CLASS {
 private:
  double longitude_;
  double latitude_;

 public:
  LonLat() {
    memset(static_cast<void *>(this), 0, sizeof(LonLat));
  }
  LonLat(double _longitude, double _latitude)
        : longitude_(flatbuffers::EndianScalar(_longitude)),
        latitude_(flatbuffers::EndianScalar(_latitude)) {
  }
  /// WGS84 경도
  double longitude() const {
    return flatbuffers::EndianScalar(longitude_);
  }
  /// WGS84 위도
  double latitude() const {
    return flatbuffers::EndianScalar(latitude_);
  }
};
FLATBUFFERS_STRUCT_END(LonLat, 16);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) RGServiceLink FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t gpType_;
  int32_t vertexIndex_;
  uint16_t turnCode_;
  int16_t padding0__;

 public:
  RGServiceLink() {
    memset(static_cast<void *>(this), 0, sizeof(RGServiceLink));
  }
  RGServiceLink(int32_t _gpType, int32_t _vertexIndex, uint16_t _turnCode)
      : gpType_(flatbuffers::EndianScalar(_gpType)),
        vertexIndex_(flatbuffers::EndianScalar(_vertexIndex)),
        turnCode_(flatbuffers::EndianScalar(_turnCode)),
        padding0__(0) {
    (void)padding0__;
  }
  /// GP의 종류
  int32_t gpType() const {
    return flatbuffers::EndianScalar(gpType_);
  }
  /// vertex index
  int32_t vertexIndex() const {
    return flatbuffers::EndianScalar(vertexIndex_);
  }
  /// 회전 코드
  uint16_t turnCode() const {
    return flatbuffers::EndianScalar(turnCode_);
  }
};
FLATBUFFERS_STRUCT_END(RGServiceLink, 12);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) LinkInfo FLATBUFFERS_FINAL_CLASS {
 private:
  uint16_t congestion_;
  int16_t padding0__;
  uint32_t tsdLinkId_;
  int32_t vertexStartIndex_;
  int32_t vertexEndIndex_;

 public:
  LinkInfo() {
    memset(static_cast<void *>(this), 0, sizeof(LinkInfo));
  }
  LinkInfo(uint16_t _congestion, uint32_t _tsdLinkId, int32_t _vertexStartIndex, int32_t _vertexEndIndex)
      : congestion_(flatbuffers::EndianScalar(_congestion)),
        padding0__(0),
        tsdLinkId_(flatbuffers::EndianScalar(_tsdLinkId)),
        vertexStartIndex_(flatbuffers::EndianScalar(_vertexStartIndex)),
        vertexEndIndex_(flatbuffers::EndianScalar(_vertexEndIndex)) {
    (void)padding0__;
  }
  /// 혼잡도 ('0':정보없음, '1':원활, '2':서행, '3':정체)
  uint16_t congestion() const {
    return flatbuffers::EndianScalar(congestion_);
  }
  /// TSD Link ID (실시간 교통 정보)
  uint32_t tsdLinkId() const {
    return flatbuffers::EndianScalar(tsdLinkId_);
  }
  /// Link의 Vertex 정보의 시작 인덱스
  int32_t vertexStartIndex() const {
    return flatbuffers::EndianScalar(vertexStartIndex_);
  }
  /// Link의 Vertex 정보의 끝인덱스
  int32_t vertexEndIndex() const {
    return flatbuffers::EndianScalar(vertexEndIndex_);
  }
};
FLATBUFFERS_STRUCT_END(LinkInfo, 16);

struct GasStationInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TYPE = 4,
    VT_BRAND = 6,
    VT_FACILITY = 8,
    VT_ROADCODE = 10,
    VT_HASPREMIUMOIL = 12,
    VT_ISLOWERPRICE = 14,
    VT_LONLAT = 16,
    VT_VERTEXINDEX = 18,
    VT_NAME = 20,
    VT_GASOLINEPRICE = 22,
    VT_DIESELPRICE = 24,
    VT_KEROSENEPRICE = 26,
    VT_LPGPRICE = 28,
    VT_PREMIUMGASOLINEPRICE = 30,
    VT_PREMIUMDIESELPRICE = 32,
    VT_PREMIUMKEROSENEPRICE = 34,
    VT_DISTANCE = 36,
    VT_POIID = 38,
    VT_ISPARTNERCARDSALE = 40
  };
  /// 주유소 형식(0 : 주유소, 1: 충전소, 2 : 주유소&충전소)
  uint8_t type() const {
    return GetField<uint8_t>(VT_TYPE, 0);
  }
  /// 주유소 브랜드 코드
  uint8_t brand() const {
    return GetField<uint8_t>(VT_BRAND, 0);
  }
  uint8_t facility() const {
    return GetField<uint8_t>(VT_FACILITY, 0);
  }
  /// 매칭된 도로 종별 코드
  uint8_t roadCode() const {
    return GetField<uint8_t>(VT_ROADCODE, 0);
  }
  /// 고급 휘발유 판매 유무(0 : 미조사, 1 : yes, 2 : no)
  uint8_t hasPremiumOil() const {
    return GetField<uint8_t>(VT_HASPREMIUMOIL, 0);
  }
  /// 최저가 유무(0 : 최저가 아님, 1 : 최저가)
  uint8_t isLowerPrice() const {
    return GetField<uint8_t>(VT_ISLOWERPRICE, 0);
  }
  /// 주유소 좌표
  const LonLat *lonLat() const {
    return GetStruct<const LonLat *>(VT_LONLAT);
  }
  /// vertex index
  int32_t vertexIndex() const {
    return GetField<int32_t>(VT_VERTEXINDEX, 0);
  }
  /// 주유소 명칭 (euc-kr)
  const flatbuffers::Vector<int8_t> *name() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_NAME);
  }
  /// 휘발유값 (이하 단위 원)
  uint16_t gasolinePrice() const {
    return GetField<uint16_t>(VT_GASOLINEPRICE, 0);
  }
  /// 경유값
  uint16_t dieselPrice() const {
    return GetField<uint16_t>(VT_DIESELPRICE, 0);
  }
  /// 등유값
  uint16_t kerosenePrice() const {
    return GetField<uint16_t>(VT_KEROSENEPRICE, 0);
  }
  /// LPG값
  uint16_t lpgPrice() const {
    return GetField<uint16_t>(VT_LPGPRICE, 0);
  }
  /// 고급 휘발유값
  uint16_t premiumGasolinePrice() const {
    return GetField<uint16_t>(VT_PREMIUMGASOLINEPRICE, 0);
  }
  /// 고급 경유값
  uint16_t premiumDieselPrice() const {
    return GetField<uint16_t>(VT_PREMIUMDIESELPRICE, 0);
  }
  /// 고급 등유값
  uint16_t premiumKerosenePrice() const {
    return GetField<uint16_t>(VT_PREMIUMKEROSENEPRICE, 0);
  }
  /// 출발지 부터의 거리
  uint32_t distance() const {
    return GetField<uint32_t>(VT_DISTANCE, 0);
  }
  /// POI ID
  uint32_t poiId() const {
    return GetField<uint32_t>(VT_POIID, 0);
  }
  /// 제휴카드 할인 유무(0: 없음, 1:있음)
  uint32_t isPartnerCardSale() const {
    return GetField<uint32_t>(VT_ISPARTNERCARDSALE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_TYPE) &&
           VerifyField<uint8_t>(verifier, VT_BRAND) &&
           VerifyField<uint8_t>(verifier, VT_FACILITY) &&
           VerifyField<uint8_t>(verifier, VT_ROADCODE) &&
           VerifyField<uint8_t>(verifier, VT_HASPREMIUMOIL) &&
           VerifyField<uint8_t>(verifier, VT_ISLOWERPRICE) &&
           VerifyField<LonLat>(verifier, VT_LONLAT) &&
           VerifyField<int32_t>(verifier, VT_VERTEXINDEX) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyVector(name()) &&
           VerifyField<uint16_t>(verifier, VT_GASOLINEPRICE) &&
           VerifyField<uint16_t>(verifier, VT_DIESELPRICE) &&
           VerifyField<uint16_t>(verifier, VT_KEROSENEPRICE) &&
           VerifyField<uint16_t>(verifier, VT_LPGPRICE) &&
           VerifyField<uint16_t>(verifier, VT_PREMIUMGASOLINEPRICE) &&
           VerifyField<uint16_t>(verifier, VT_PREMIUMDIESELPRICE) &&
           VerifyField<uint16_t>(verifier, VT_PREMIUMKEROSENEPRICE) &&
           VerifyField<uint32_t>(verifier, VT_DISTANCE) &&
           VerifyField<uint32_t>(verifier, VT_POIID) &&
           VerifyField<uint32_t>(verifier, VT_ISPARTNERCARDSALE) &&
           verifier.EndTable();
  }
};

struct GasStationInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(uint8_t type) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_TYPE, type, 0);
  }
  void add_brand(uint8_t brand) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_BRAND, brand, 0);
  }
  void add_facility(uint8_t facility) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_FACILITY, facility, 0);
  }
  void add_roadCode(uint8_t roadCode) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_ROADCODE, roadCode, 0);
  }
  void add_hasPremiumOil(uint8_t hasPremiumOil) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_HASPREMIUMOIL, hasPremiumOil, 0);
  }
  void add_isLowerPrice(uint8_t isLowerPrice) {
    fbb_.AddElement<uint8_t>(GasStationInfo::VT_ISLOWERPRICE, isLowerPrice, 0);
  }
  void add_lonLat(const LonLat *lonLat) {
    fbb_.AddStruct(GasStationInfo::VT_LONLAT, lonLat);
  }
  void add_vertexIndex(int32_t vertexIndex) {
    fbb_.AddElement<int32_t>(GasStationInfo::VT_VERTEXINDEX, vertexIndex, 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::Vector<int8_t>> name) {
    fbb_.AddOffset(GasStationInfo::VT_NAME, name);
  }
  void add_gasolinePrice(uint16_t gasolinePrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_GASOLINEPRICE, gasolinePrice, 0);
  }
  void add_dieselPrice(uint16_t dieselPrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_DIESELPRICE, dieselPrice, 0);
  }
  void add_kerosenePrice(uint16_t kerosenePrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_KEROSENEPRICE, kerosenePrice, 0);
  }
  void add_lpgPrice(uint16_t lpgPrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_LPGPRICE, lpgPrice, 0);
  }
  void add_premiumGasolinePrice(uint16_t premiumGasolinePrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_PREMIUMGASOLINEPRICE, premiumGasolinePrice, 0);
  }
  void add_premiumDieselPrice(uint16_t premiumDieselPrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_PREMIUMDIESELPRICE, premiumDieselPrice, 0);
  }
  void add_premiumKerosenePrice(uint16_t premiumKerosenePrice) {
    fbb_.AddElement<uint16_t>(GasStationInfo::VT_PREMIUMKEROSENEPRICE, premiumKerosenePrice, 0);
  }
  void add_distance(uint32_t distance) {
    fbb_.AddElement<uint32_t>(GasStationInfo::VT_DISTANCE, distance, 0);
  }
  void add_poiId(uint32_t poiId) {
    fbb_.AddElement<uint32_t>(GasStationInfo::VT_POIID, poiId, 0);
  }
  void add_isPartnerCardSale(uint32_t isPartnerCardSale) {
    fbb_.AddElement<uint32_t>(GasStationInfo::VT_ISPARTNERCARDSALE, isPartnerCardSale, 0);
  }
  explicit GasStationInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GasStationInfoBuilder &operator=(const GasStationInfoBuilder &);
  flatbuffers::Offset<GasStationInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GasStationInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<GasStationInfo> CreateGasStationInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint8_t type = 0,
    uint8_t brand = 0,
    uint8_t facility = 0,
    uint8_t roadCode = 0,
    uint8_t hasPremiumOil = 0,
    uint8_t isLowerPrice = 0,
    const LonLat *lonLat = 0,
    int32_t vertexIndex = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> name = 0,
    uint16_t gasolinePrice = 0,
    uint16_t dieselPrice = 0,
    uint16_t kerosenePrice = 0,
    uint16_t lpgPrice = 0,
    uint16_t premiumGasolinePrice = 0,
    uint16_t premiumDieselPrice = 0,
    uint16_t premiumKerosenePrice = 0,
    uint32_t distance = 0,
    uint32_t poiId = 0,
    uint32_t isPartnerCardSale = 0) {
  GasStationInfoBuilder builder_(_fbb);
  builder_.add_isPartnerCardSale(isPartnerCardSale);
  builder_.add_poiId(poiId);
  builder_.add_distance(distance);
  builder_.add_name(name);
  builder_.add_vertexIndex(vertexIndex);
  builder_.add_lonLat(lonLat);
  builder_.add_premiumKerosenePrice(premiumKerosenePrice);
  builder_.add_premiumDieselPrice(premiumDieselPrice);
  builder_.add_premiumGasolinePrice(premiumGasolinePrice);
  builder_.add_lpgPrice(lpgPrice);
  builder_.add_kerosenePrice(kerosenePrice);
  builder_.add_dieselPrice(dieselPrice);
  builder_.add_gasolinePrice(gasolinePrice);
  builder_.add_isLowerPrice(isLowerPrice);
  builder_.add_hasPremiumOil(hasPremiumOil);
  builder_.add_roadCode(roadCode);
  builder_.add_facility(facility);
  builder_.add_brand(brand);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<GasStationInfo> CreateGasStationInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint8_t type = 0,
    uint8_t brand = 0,
    uint8_t facility = 0,
    uint8_t roadCode = 0,
    uint8_t hasPremiumOil = 0,
    uint8_t isLowerPrice = 0,
    const LonLat *lonLat = 0,
    int32_t vertexIndex = 0,
    const std::vector<int8_t> *name = nullptr,
    uint16_t gasolinePrice = 0,
    uint16_t dieselPrice = 0,
    uint16_t kerosenePrice = 0,
    uint16_t lpgPrice = 0,
    uint16_t premiumGasolinePrice = 0,
    uint16_t premiumDieselPrice = 0,
    uint16_t premiumKerosenePrice = 0,
    uint32_t distance = 0,
    uint32_t poiId = 0,
    uint32_t isPartnerCardSale = 0) {
  auto name__ = name ? _fbb.CreateVector<int8_t>(*name) : 0;
  return vsm::route::CreateGasStationInfo(
      _fbb,
      type,
      brand,
      facility,
      roadCode,
      hasPremiumOil,
      isLowerPrice,
      lonLat,
      vertexIndex,
      name__,
      gasolinePrice,
      dieselPrice,
      kerosenePrice,
      lpgPrice,
      premiumGasolinePrice,
      premiumDieselPrice,
      premiumKerosenePrice,
      distance,
      poiId,
      isPartnerCardSale);
}

struct PositionInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_LONLAT = 4,
    VT_POSITIONNAME = 6
  };
  /// 지점 좌표
  const LonLat *lonLat() const {
    return GetStruct<const LonLat *>(VT_LONLAT);
  }
  /// 지점 명칭 (euc-kr)
  const flatbuffers::Vector<int8_t> *positionName() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_POSITIONNAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<LonLat>(verifier, VT_LONLAT) &&
           VerifyOffset(verifier, VT_POSITIONNAME) &&
           verifier.VerifyVector(positionName()) &&
           verifier.EndTable();
  }
};

struct PositionInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_lonLat(const LonLat *lonLat) {
    fbb_.AddStruct(PositionInfo::VT_LONLAT, lonLat);
  }
  void add_positionName(flatbuffers::Offset<flatbuffers::Vector<int8_t>> positionName) {
    fbb_.AddOffset(PositionInfo::VT_POSITIONNAME, positionName);
  }
  explicit PositionInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PositionInfoBuilder &operator=(const PositionInfoBuilder &);
  flatbuffers::Offset<PositionInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PositionInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<PositionInfo> CreatePositionInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    const LonLat *lonLat = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> positionName = 0) {
  PositionInfoBuilder builder_(_fbb);
  builder_.add_positionName(positionName);
  builder_.add_lonLat(lonLat);
  return builder_.Finish();
}

inline flatbuffers::Offset<PositionInfo> CreatePositionInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const LonLat *lonLat = 0,
    const std::vector<int8_t> *positionName = nullptr) {
  auto positionName__ = positionName ? _fbb.CreateVector<int8_t>(*positionName) : 0;
  return vsm::route::CreatePositionInfo(
      _fbb,
      lonLat,
      positionName__);
}

struct AccidentInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VERTEXINDEX = 4,
    VT_CODE = 6,
    VT_DESCRIPTION = 8
  };
  /// vertex index
  int32_t vertexIndex() const {
    return GetField<int32_t>(VT_VERTEXINDEX, 0);
  }
  /// 구분 코드(A:사고, B:공사, C:행사, D:재해, E:통제)
  uint8_t code() const {
    return GetField<uint8_t>(VT_CODE, 0);
  }
  /// 사고 내용
  const flatbuffers::Vector<int8_t> *description() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_DESCRIPTION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_VERTEXINDEX) &&
           VerifyField<uint8_t>(verifier, VT_CODE) &&
           VerifyOffset(verifier, VT_DESCRIPTION) &&
           verifier.VerifyVector(description()) &&
           verifier.EndTable();
  }
};

struct AccidentInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_vertexIndex(int32_t vertexIndex) {
    fbb_.AddElement<int32_t>(AccidentInfo::VT_VERTEXINDEX, vertexIndex, 0);
  }
  void add_code(uint8_t code) {
    fbb_.AddElement<uint8_t>(AccidentInfo::VT_CODE, code, 0);
  }
  void add_description(flatbuffers::Offset<flatbuffers::Vector<int8_t>> description) {
    fbb_.AddOffset(AccidentInfo::VT_DESCRIPTION, description);
  }
  explicit AccidentInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AccidentInfoBuilder &operator=(const AccidentInfoBuilder &);
  flatbuffers::Offset<AccidentInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<AccidentInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<AccidentInfo> CreateAccidentInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t vertexIndex = 0,
    uint8_t code = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> description = 0) {
  AccidentInfoBuilder builder_(_fbb);
  builder_.add_description(description);
  builder_.add_vertexIndex(vertexIndex);
  builder_.add_code(code);
  return builder_.Finish();
}

inline flatbuffers::Offset<AccidentInfo> CreateAccidentInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t vertexIndex = 0,
    uint8_t code = 0,
    const std::vector<int8_t> *description = nullptr) {
  auto description__ = description ? _fbb.CreateVector<int8_t>(*description) : 0;
  return vsm::route::CreateAccidentInfo(
      _fbb,
      vertexIndex,
      code,
      description__);
}

struct EVStationInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VERTEXINDEX = 4,
    VT_POIID = 6,
    VT_ROADCODE = 8,
    VT_LONLAT = 10,
    VT_ONROUTE = 12,
    VT_DCCHA = 14,
    VT_AC3 = 16,
    VT_DCCOMBO = 18,
    VT_SLOWCHARGE = 20,
    VT_SUPERCHARGE = 22,
    VT_NAME = 24
  };
  /// vertex index
  int32_t vertexIndex() const {
    return GetField<int32_t>(VT_VERTEXINDEX, 0);
  }
  /// POI ID
  int32_t poiId() const {
    return GetField<int32_t>(VT_POIID, 0);
  }
  /// 도로종별 코드
  uint8_t roadCode() const {
    return GetField<uint8_t>(VT_ROADCODE, 0);
  }
  /// 주유소 좌표
  const LonLat *lonLat() const {
    return GetStruct<const LonLat *>(VT_LONLAT);
  }
  /// 충전소 경로상 존재 여부 (0:경로상, 1:경로주변)
  uint8_t onRoute() const {
    return GetField<uint8_t>(VT_ONROUTE, 0);
  }
  /// DcCHA 지원여부 (0:미지원, 1:지원)
  uint8_t DcCHA() const {
    return GetField<uint8_t>(VT_DCCHA, 0);
  }
  /// AC3 지원여부 (0:미지원, 1:지원)
  uint8_t AC3() const {
    return GetField<uint8_t>(VT_AC3, 0);
  }
  /// DcCombo 지원 여부 (0:미지원, 1:지원)
  uint8_t DcCombo() const {
    return GetField<uint8_t>(VT_DCCOMBO, 0);
  }
  /// 저속충전 지원 여부 (0:미지원, 1:지원)
  uint8_t slowCharge() const {
    return GetField<uint8_t>(VT_SLOWCHARGE, 0);
  }
  /// 테슬라 슈퍼차지 (0:미지원, 1:지원)
  uint8_t superCharge() const {
    return GetField<uint8_t>(VT_SUPERCHARGE, 0);
  }
  /// 주유소 명칭 (euc-kr)
  const flatbuffers::Vector<int8_t> *name() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_VERTEXINDEX) &&
           VerifyField<int32_t>(verifier, VT_POIID) &&
           VerifyField<uint8_t>(verifier, VT_ROADCODE) &&
           VerifyField<LonLat>(verifier, VT_LONLAT) &&
           VerifyField<uint8_t>(verifier, VT_ONROUTE) &&
           VerifyField<uint8_t>(verifier, VT_DCCHA) &&
           VerifyField<uint8_t>(verifier, VT_AC3) &&
           VerifyField<uint8_t>(verifier, VT_DCCOMBO) &&
           VerifyField<uint8_t>(verifier, VT_SLOWCHARGE) &&
           VerifyField<uint8_t>(verifier, VT_SUPERCHARGE) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyVector(name()) &&
           verifier.EndTable();
  }
};

struct EVStationInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_vertexIndex(int32_t vertexIndex) {
    fbb_.AddElement<int32_t>(EVStationInfo::VT_VERTEXINDEX, vertexIndex, 0);
  }
  void add_poiId(int32_t poiId) {
    fbb_.AddElement<int32_t>(EVStationInfo::VT_POIID, poiId, 0);
  }
  void add_roadCode(uint8_t roadCode) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_ROADCODE, roadCode, 0);
  }
  void add_lonLat(const LonLat *lonLat) {
    fbb_.AddStruct(EVStationInfo::VT_LONLAT, lonLat);
  }
  void add_onRoute(uint8_t onRoute) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_ONROUTE, onRoute, 0);
  }
  void add_DcCHA(uint8_t DcCHA) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_DCCHA, DcCHA, 0);
  }
  void add_AC3(uint8_t AC3) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_AC3, AC3, 0);
  }
  void add_DcCombo(uint8_t DcCombo) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_DCCOMBO, DcCombo, 0);
  }
  void add_slowCharge(uint8_t slowCharge) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_SLOWCHARGE, slowCharge, 0);
  }
  void add_superCharge(uint8_t superCharge) {
    fbb_.AddElement<uint8_t>(EVStationInfo::VT_SUPERCHARGE, superCharge, 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::Vector<int8_t>> name) {
    fbb_.AddOffset(EVStationInfo::VT_NAME, name);
  }
  explicit EVStationInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  EVStationInfoBuilder &operator=(const EVStationInfoBuilder &);
  flatbuffers::Offset<EVStationInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<EVStationInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<EVStationInfo> CreateEVStationInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t vertexIndex = 0,
    int32_t poiId = 0,
    uint8_t roadCode = 0,
    const LonLat *lonLat = 0,
    uint8_t onRoute = 0,
    uint8_t DcCHA = 0,
    uint8_t AC3 = 0,
    uint8_t DcCombo = 0,
    uint8_t slowCharge = 0,
    uint8_t superCharge = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> name = 0) {
  EVStationInfoBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_lonLat(lonLat);
  builder_.add_poiId(poiId);
  builder_.add_vertexIndex(vertexIndex);
  builder_.add_superCharge(superCharge);
  builder_.add_slowCharge(slowCharge);
  builder_.add_DcCombo(DcCombo);
  builder_.add_AC3(AC3);
  builder_.add_DcCHA(DcCHA);
  builder_.add_onRoute(onRoute);
  builder_.add_roadCode(roadCode);
  return builder_.Finish();
}

inline flatbuffers::Offset<EVStationInfo> CreateEVStationInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t vertexIndex = 0,
    int32_t poiId = 0,
    uint8_t roadCode = 0,
    const LonLat *lonLat = 0,
    uint8_t onRoute = 0,
    uint8_t DcCHA = 0,
    uint8_t AC3 = 0,
    uint8_t DcCombo = 0,
    uint8_t slowCharge = 0,
    uint8_t superCharge = 0,
    const std::vector<int8_t> *name = nullptr) {
  auto name__ = name ? _fbb.CreateVector<int8_t>(*name) : 0;
  return vsm::route::CreateEVStationInfo(
      _fbb,
      vertexIndex,
      poiId,
      roadCode,
      lonLat,
      onRoute,
      DcCHA,
      AC3,
      DcCombo,
      slowCharge,
      superCharge,
      name__);
}

struct RouteData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_LINKLIST = 4,
    VT_RGSERVICELINKLIST = 6,
    VT_VERTEXLIST = 8,
    VT_GASSTATIONLIST = 10,
    VT_ROUTETYPE = 12,
    VT_TVASID = 14,
    VT_MAINROADLIST = 16,
    VT_POSITIONLIST = 18,
    VT_ACCIDENTINFOLIST = 20,
    VT_EVSTATIONLIST = 22,
    VT_OPPOSITESIDEVERTEXINDEX = 24
  };
  const flatbuffers::Vector<const LinkInfo *> *linkList() const {
    return GetPointer<const flatbuffers::Vector<const LinkInfo *> *>(VT_LINKLIST);
  }
  const flatbuffers::Vector<const RGServiceLink *> *rgServiceLinkList() const {
    return GetPointer<const flatbuffers::Vector<const RGServiceLink *> *>(VT_RGSERVICELINKLIST);
  }
  const flatbuffers::Vector<const LonLat *> *vertexList() const {
    return GetPointer<const flatbuffers::Vector<const LonLat *> *>(VT_VERTEXLIST);
  }
  const flatbuffers::Vector<flatbuffers::Offset<GasStationInfo>> *gasStationList() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<GasStationInfo>> *>(VT_GASSTATIONLIST);
  }
  /// 경로 타입 1:주행경로, 2:대안경로
  uint8_t routeType() const {
    return GetField<uint8_t>(VT_ROUTETYPE, 0);
  }
  /// 이전 tvas데이터와 현재 tvas데이터를 구분할 수 있는 식별 id
  int32_t tvasId() const {
    return GetField<int32_t>(VT_TVASID, 0);
  }
  /// 주요경로 출력
  const flatbuffers::Vector<flatbuffers::Offset<PositionInfo>> *mainRoadList() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<PositionInfo>> *>(VT_MAINROADLIST);
  }
  /// 좌표 정보 (0:출발지, 1:경유지1, 2:경유지2, ..., n:목적지)
  const flatbuffers::Vector<flatbuffers::Offset<PositionInfo>> *positionList() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<PositionInfo>> *>(VT_POSITIONLIST);
  }
  /// 유고정보
  const flatbuffers::Vector<flatbuffers::Offset<AccidentInfo>> *accidentInfoList() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<AccidentInfo>> *>(VT_ACCIDENTINFOLIST);
  }
  /// 전기차 충전소 정보
  const flatbuffers::Vector<flatbuffers::Offset<EVStationInfo>> *evStationList() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<EVStationInfo>> *>(VT_EVSTATIONLIST);
  }
  /// 목적지 건너편 지점 (0: 미사용)
  int32_t oppositeSideVertexIndex() const {
    return GetField<int32_t>(VT_OPPOSITESIDEVERTEXINDEX, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_LINKLIST) &&
           verifier.VerifyVector(linkList()) &&
           VerifyOffset(verifier, VT_RGSERVICELINKLIST) &&
           verifier.VerifyVector(rgServiceLinkList()) &&
           VerifyOffset(verifier, VT_VERTEXLIST) &&
           verifier.VerifyVector(vertexList()) &&
           VerifyOffset(verifier, VT_GASSTATIONLIST) &&
           verifier.VerifyVector(gasStationList()) &&
           verifier.VerifyVectorOfTables(gasStationList()) &&
           VerifyField<uint8_t>(verifier, VT_ROUTETYPE) &&
           VerifyField<int32_t>(verifier, VT_TVASID) &&
           VerifyOffset(verifier, VT_MAINROADLIST) &&
           verifier.VerifyVector(mainRoadList()) &&
           verifier.VerifyVectorOfTables(mainRoadList()) &&
           VerifyOffset(verifier, VT_POSITIONLIST) &&
           verifier.VerifyVector(positionList()) &&
           verifier.VerifyVectorOfTables(positionList()) &&
           VerifyOffset(verifier, VT_ACCIDENTINFOLIST) &&
           verifier.VerifyVector(accidentInfoList()) &&
           verifier.VerifyVectorOfTables(accidentInfoList()) &&
           VerifyOffset(verifier, VT_EVSTATIONLIST) &&
           verifier.VerifyVector(evStationList()) &&
           verifier.VerifyVectorOfTables(evStationList()) &&
           VerifyField<int32_t>(verifier, VT_OPPOSITESIDEVERTEXINDEX) &&
           verifier.EndTable();
  }
};

struct RouteDataBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_linkList(flatbuffers::Offset<flatbuffers::Vector<const LinkInfo *>> linkList) {
    fbb_.AddOffset(RouteData::VT_LINKLIST, linkList);
  }
  void add_rgServiceLinkList(flatbuffers::Offset<flatbuffers::Vector<const RGServiceLink *>> rgServiceLinkList) {
    fbb_.AddOffset(RouteData::VT_RGSERVICELINKLIST, rgServiceLinkList);
  }
  void add_vertexList(flatbuffers::Offset<flatbuffers::Vector<const LonLat *>> vertexList) {
    fbb_.AddOffset(RouteData::VT_VERTEXLIST, vertexList);
  }
  void add_gasStationList(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<GasStationInfo>>> gasStationList) {
    fbb_.AddOffset(RouteData::VT_GASSTATIONLIST, gasStationList);
  }
  void add_routeType(uint8_t routeType) {
    fbb_.AddElement<uint8_t>(RouteData::VT_ROUTETYPE, routeType, 0);
  }
  void add_tvasId(int32_t tvasId) {
    fbb_.AddElement<int32_t>(RouteData::VT_TVASID, tvasId, 0);
  }
  void add_mainRoadList(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PositionInfo>>> mainRoadList) {
    fbb_.AddOffset(RouteData::VT_MAINROADLIST, mainRoadList);
  }
  void add_positionList(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PositionInfo>>> positionList) {
    fbb_.AddOffset(RouteData::VT_POSITIONLIST, positionList);
  }
  void add_accidentInfoList(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<AccidentInfo>>> accidentInfoList) {
    fbb_.AddOffset(RouteData::VT_ACCIDENTINFOLIST, accidentInfoList);
  }
  void add_evStationList(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EVStationInfo>>> evStationList) {
    fbb_.AddOffset(RouteData::VT_EVSTATIONLIST, evStationList);
  }
  void add_oppositeSideVertexIndex(int32_t oppositeSideVertexIndex) {
    fbb_.AddElement<int32_t>(RouteData::VT_OPPOSITESIDEVERTEXINDEX, oppositeSideVertexIndex, 0);
  }
  explicit RouteDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RouteDataBuilder &operator=(const RouteDataBuilder &);
  flatbuffers::Offset<RouteData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<RouteData>(end);
    return o;
  }
};

inline flatbuffers::Offset<RouteData> CreateRouteData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<const LinkInfo *>> linkList = 0,
    flatbuffers::Offset<flatbuffers::Vector<const RGServiceLink *>> rgServiceLinkList = 0,
    flatbuffers::Offset<flatbuffers::Vector<const LonLat *>> vertexList = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<GasStationInfo>>> gasStationList = 0,
    uint8_t routeType = 0,
    int32_t tvasId = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PositionInfo>>> mainRoadList = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PositionInfo>>> positionList = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<AccidentInfo>>> accidentInfoList = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EVStationInfo>>> evStationList = 0,
    int32_t oppositeSideVertexIndex = 0) {
  RouteDataBuilder builder_(_fbb);
  builder_.add_oppositeSideVertexIndex(oppositeSideVertexIndex);
  builder_.add_evStationList(evStationList);
  builder_.add_accidentInfoList(accidentInfoList);
  builder_.add_positionList(positionList);
  builder_.add_mainRoadList(mainRoadList);
  builder_.add_tvasId(tvasId);
  builder_.add_gasStationList(gasStationList);
  builder_.add_vertexList(vertexList);
  builder_.add_rgServiceLinkList(rgServiceLinkList);
  builder_.add_linkList(linkList);
  builder_.add_routeType(routeType);
  return builder_.Finish();
}

inline flatbuffers::Offset<RouteData> CreateRouteDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<LinkInfo> *linkList = nullptr,
    const std::vector<RGServiceLink> *rgServiceLinkList = nullptr,
    const std::vector<LonLat> *vertexList = nullptr,
    const std::vector<flatbuffers::Offset<GasStationInfo>> *gasStationList = nullptr,
    uint8_t routeType = 0,
    int32_t tvasId = 0,
    const std::vector<flatbuffers::Offset<PositionInfo>> *mainRoadList = nullptr,
    const std::vector<flatbuffers::Offset<PositionInfo>> *positionList = nullptr,
    const std::vector<flatbuffers::Offset<AccidentInfo>> *accidentInfoList = nullptr,
    const std::vector<flatbuffers::Offset<EVStationInfo>> *evStationList = nullptr,
    int32_t oppositeSideVertexIndex = 0) {
  auto linkList__ = linkList ? _fbb.CreateVectorOfStructs<LinkInfo>(*linkList) : 0;
  auto rgServiceLinkList__ = rgServiceLinkList ? _fbb.CreateVectorOfStructs<RGServiceLink>(*rgServiceLinkList) : 0;
  auto vertexList__ = vertexList ? _fbb.CreateVectorOfStructs<LonLat>(*vertexList) : 0;
  auto gasStationList__ = gasStationList ? _fbb.CreateVector<flatbuffers::Offset<GasStationInfo>>(*gasStationList) : 0;
  auto mainRoadList__ = mainRoadList ? _fbb.CreateVector<flatbuffers::Offset<PositionInfo>>(*mainRoadList) : 0;
  auto positionList__ = positionList ? _fbb.CreateVector<flatbuffers::Offset<PositionInfo>>(*positionList) : 0;
  auto accidentInfoList__ = accidentInfoList ? _fbb.CreateVector<flatbuffers::Offset<AccidentInfo>>(*accidentInfoList) : 0;
  auto evStationList__ = evStationList ? _fbb.CreateVector<flatbuffers::Offset<EVStationInfo>>(*evStationList) : 0;
  return vsm::route::CreateRouteData(
      _fbb,
      linkList__,
      rgServiceLinkList__,
      vertexList__,
      gasStationList__,
      routeType,
      tvasId,
      mainRoadList__,
      positionList__,
      accidentInfoList__,
      evStationList__,
      oppositeSideVertexIndex);
}

inline const vsm::route::RouteData *GetRouteData(const void *buf) {
  return flatbuffers::GetRoot<vsm::route::RouteData>(buf);
}

inline const vsm::route::RouteData *GetSizePrefixedRouteData(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<vsm::route::RouteData>(buf);
}

inline bool VerifyRouteDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<vsm::route::RouteData>(nullptr);
}

inline bool VerifySizePrefixedRouteDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<vsm::route::RouteData>(nullptr);
}

inline void FinishRouteDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<vsm::route::RouteData> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedRouteDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<vsm::route::RouteData> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace route
}  // namespace vsm

#endif  // FLATBUFFERS_GENERATED_VSMROUTE_VSM_ROUTE_H_
