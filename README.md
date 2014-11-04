Cinder-Lessons
==============

Samples demonstrating basic techniques with Cinder.

## Creating a new Project

Cinder provides a tool called TinderBox for creating new projects.

- Open Cinder/tools/TinderBox-(yourplatform)/TinderBox

You will see a screen that looks like this:
![tinderbox-start](https://cloud.githubusercontent.com/assets/81553/4901039/fe0d81aa-642d-11e4-9801-2c37f5980158.png)

If you have multiple copies of Cinder on your machine, make sure to point TinderBox at the correct one. In TinderBox, this is called your “Cinder Version”, and is selected from a drop-down menu. You can update the contents of the dropdown by opening the “Settings...” section.
![tinderbox-preferences](https://cloud.githubusercontent.com/assets/81553/4901037/fe06a06a-642d-11e4-95bc-5c9e1c1476cf.png)

- You can select a template to build off of from here. The templates are provided via Cinder blocks.
- Select the build environments you want to target. At soso, this will be XCode for most things.
- Click on “Next” to choose any blocks you want to include in your project.
	- For long-term project maintainability, I usually have Cinder as a submodule of my project repository. You can then install the default Cinder blocks relative to your project.
	- Unfortunately, you can’t have a top-level repository control a folder inside of a submodule, so this makes it tricky to have non-default Cinder blocks supported by TinderBox and your git repository. I add non-default blocks as submodules to my project and add their contents to my projects manually.
	- In the future, TinderBox should support alternative locations for Cinder blocks so we can still get access to templates and easier setup for blocks that are also added as project submodules.
![tinderbox-blocks](https://cloud.githubusercontent.com/assets/81553/4901036/fdfe545a-642d-11e4-83a6-3dfee3a0ce0b.png)

- Click on "Finish" to create your project and open it in Finder/Explorer.
![tinderbox-result](https://cloud.githubusercontent.com/assets/81553/4901038/fe0a4f80-642d-11e4-9e5c-ff1ccc2c8bc0.png)
