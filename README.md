# CPPShooter_JSONHTTPLoading

A simple First Person shooter that uses HTTP and JSON modules of Unreal Engine 5.6.1 to fetch data from the internet and dynamically create cube actors based on the json data.

**Progress:**

1. I found that the dynamically spawning objects using json data from the internet is the rate determining step for this project. Hence I decided to proceed with this for two reasons:
  i) I had never worked with json files before, I got to know about them during this assignment and essentially, a part of this assignment is also a educational experience for me. I had also never worked with        fetching values from the internet before. So this was a challenge that I sought to figure out.
  ii) Since, this was the hardest part to complete, I figured to complete this part of assignment first.

I was able to successfully use the C++ API to fetch data from the internet into the project. I couldn't use that data to spawn objects. Need to figure that out.

**Obstacles:**

1. Having installed UE 5.6 for the first time, I had some issues running it at an acceptable frame rate on my laptop initially.

2. Later, a Vulnerability Warning was Encountered, which was later resolved.
    Date: September 9, 2025
    Project: Unreal Engine 5.6
    Issue: During development, a warning was triggered regarding a known vulnerability in the NuGet package:
    
    Package: Magick.NET-Q16-HDRI-AnyCPU
    Version: 14.7.0
    Severity: Moderate to High
    Advisory: GHSA-6hgw-6x87-578x
    Description: The vulnerability involves a potential infinite loop in image processing due to malformed XMP profile data, which can lead to a denial of service (DoS).
    Mitigation: Upgrade to version 14.8.2 or later to resolve the issue.

   3. Aptitude Issue: I am not from a CS background, I am learning C++ as I go along in my game development journey. Since, I had laser focused myself on creating games from base C++, I kinda forgot to revise       my Unreal C++. So it took a long time to refresh memory on Unreal C++ development.

**Existing Functionality:**

    You can play the game in the TEST_LEVEL using BP_ShooterGameMode. Later check the output log for the fetched json file. It has an "Error" flag.
   <img width="452" height="330" alt="image" src="https://github.com/user-attachments/assets/162d0a83-c45e-4436-b2a9-b2257d6b9d6e" />

   Here is the **YouTube** Link: https://youtu.be/rNYH6Yox9tU

**Sources:**

  1.  https://dev.epicgames.com/community/learning/tutorials/ZdXD/call-rest-api-using-http-json-from-ue5-c#usefullinks

  2. https://pastebin.com/sN4ddwd2

  3. https://www.orfeasel.com/parsing-json-files/

  4. https://www.youtube.com/watch?v=vLGZp5hl6qU

  5. https://youtu.be/_GQwpppMgiI?si=sdfSstfJqakUjQWL

