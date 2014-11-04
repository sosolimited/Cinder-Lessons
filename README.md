Cinder-Lessons
==============

Samples demonstrating basic techniques with Cinder.

## The Samples

No samples have been written yet. The following is a list of planned samples (coming soon!).

- Simple Drawing: immediate-mode style drawing and drawing primitives.
- File IO: loading text, JSON, XML, images, (static media).
- Retained Drawing: working with cinder::gl::Batch for more efficient drawing.

## Creating a new Project

Cinder provides a tool called TinderBox for creating new projects.

- Open Cinder/tools/TinderBox-(yourplatform)/TinderBox

You will see a screen that looks like this:
![tinderbox-start](https://cloud.githubusercontent.com/assets/81553/4901039/fe0d81aa-642d-11e4-9801-2c37f5980158.png)
- Select a template to build off of from here. The default `Basic OpenGL` is fine. You can get more templates via Cinder blocks.
- Select the build environments you want to target. At soso, this will be XCode for most things.

If you have multiple copies of Cinder on your machine, make sure to point TinderBox at the correct one. In TinderBox, this is called your `Cinder Version`, and is selected from a drop-down menu. You can update the contents of the dropdown by clicking on the `Settings...` button. I have a version named Cinder-Lessons that points to the copy of Cinder in this repository.
![tinderbox-preferences](https://cloud.githubusercontent.com/assets/81553/4901037/fe06a06a-642d-11e4-95bc-5c9e1c1476cf.png)

- Click on `Next` to choose any blocks you want to include in your project.
![tinderbox-blocks](https://cloud.githubusercontent.com/assets/81553/4901036/fdfe545a-642d-11e4-83a6-3dfee3a0ce0b.png)
For long-term project maintainability, I usually have Cinder as a submodule of my project repository (as this repository does). You can then install the default Cinder blocks relative to your project. Unfortunately, you can’t have a top-level repository control a folder inside of a submodule, so this makes it tricky to have non-default Cinder blocks supported by TinderBox and your git repository. Instead, I add non-default blocks as submodules to my project and add their contents to my projects manually. In the future, TinderBox should support alternative locations for Cinder blocks so we can use templates and automatic project configuration for blocks that are also added as project submodules.

- Click on `Finish` to create your project and open it in Finder/Explorer.
![tinderbox-result](https://cloud.githubusercontent.com/assets/81553/4901038/fe0a4f80-642d-11e4-9e5c-ff1ccc2c8bc0.png)

You are now ready to dive into the code on your freshly-created Cinder project.


## Troubleshooting

### Program Won’t Compile
If your project doesn't compile because of linker errors, make sure you have built the Cinder library. Cinder is built as a static library, which means all of its code is compiled up-front and then the parts you use are copied into your program when it is compiled. For that reason, you must build Cinder before you can build your application. Fortunately, this is easy and can be done a few ways:

1) Run the fullbuild script on OSX to build everything.
```bash
cd Cinder/xcode
./fullbuild.sh
```
2) Open the Xcode project or Visual Studio solution and build the targets you need. In visual studio, you can set up a batch build to build all of the targets at once. The fullbuild script on OSX is a workaround for Xcode lacking that functionality.

### Program Crashing Outside Your Code
If your program is crashing with strange errors whenever you call a Cinder function, or somewhere in a system library, rebuild Cinder. A while ago, David wrote a [forum post](https://forum.libcinder.org/topic/seeing-something-odd-rebuild-cinder) explaining why this is necessary. A brief summary follows.

Your program understands Cinder by the declarations provided in the various header files (.h). The headers are your map or atlas. The actual code that is executed by your program is provided by the Cinder binaries (libcinder.a). The binaries are the world. If you have updated the Cinder headers (e.g. by doing a git pull) but not rebuilt the Cinder binaries, there can be a mismatch between your map and the world. If you have planned everything by the map and can’t compensate once you are in the world, you will have problems.

Another way your world can differ from the map is when you switch compilers. Often, this quietly happens when you update Xcode. Make sure you rebuild all the libraries you depend on when you update your compile.

The solution is almost always: rebuild Cinder.

### Other

There are myriad ways things can go wrong in a program written in any language. C++ has some particularly special ways. We reduce the possibility of those errors by constraining the ways we use the language. Some of those ideas are outlined in our [C++ Lessons](https://github.com/sosolimited/Cpp-Lessons).
