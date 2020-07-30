#pragma once

#include <vector>

#include "ofMain.h"
#include "ofRectangle.h"
#include "ofPath.h"

//--------------------------------------------------

class ofxTrueTypeFontUC{
  
public:
  ofxTrueTypeFontUC();
  virtual ~ofxTrueTypeFontUC();

  //set the default dpi for all typefaces.
  static void setGlobalDpi(int newDpi);

  // 			-- default (without dpi), anti aliased, 96 dpi:
  bool load(string filename, int fontsize, bool bAntiAliased=true, bool makeContours=false, float simplifyAmt=0.3, int dpi=0);
  bool loadFont(string filename, int fontsize, bool bAntiAliased=true, bool makeContours=false, float simplifyAmt=0.3, int dpi=0);
  void reloadFont();
  void unloadFont();

  void drawString(const string &str, float x, float y);
  void drawStringAsShapes(const string &str, float x, float y);

  vector<ofPath> getStringAsPoints(const string &str, bool vflip=ofIsVFlipped());
  ofRectangle getStringBoundingBox(const string &str, float x, float y);

  bool isLoaded();
  bool isAntiAliased();

  int getFontSize();

  float getLineHeight();
  void setLineHeight(float height);

  float getLetterSpacing();
  void setLetterSpacing(float spacing);

  float getSpaceSize();
  void setSpaceSize(float size);

  float stringWidth(const string &str);
  float stringHeight(const string &str);
  int	getLoadedCharactersCount();
  int getLimitCharactersNum();
  void reserveCharacters(int charactersNumber);

private:
  class Impl;
  Impl *mImpl;

  // disallow copy and assign
  ofxTrueTypeFontUC(const ofxTrueTypeFontUC &);
  void operator=(const ofxTrueTypeFontUC &);
};
