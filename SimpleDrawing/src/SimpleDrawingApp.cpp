#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleDrawingApp : public AppNative {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void SimpleDrawingApp::setup()
{
}

void SimpleDrawingApp::mouseDown( MouseEvent event )
{
}

void SimpleDrawingApp::update()
{
}

void SimpleDrawingApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( SimpleDrawingApp, RendererGl )
