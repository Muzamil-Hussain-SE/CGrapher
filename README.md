# CGrapher

A terminal-based 2D coordinate geometry tool written in C. You can plot points on a grid, calculate distances, find slopes, measure angles, and export everything to an HTML file — all from the command line.

---

## What it does

The program gives you a simple menu you navigate with the arrow keys. From there you can:

- **Plot points** on a 53×53 ASCII grid (from -26 to +26 on both axes)
- **Calculate distance** between any two plotted points, or from the origin
- **Find the angle** a point makes with the origin (using `atan2`)
- **Calculate slope** between two points
- **Export results** to a formatted HTML file (`Export_result.html`)

Points are labeled alphabetically starting from A, and you can add as many as you want during a session.

---

## Building

This project uses Windows-specific headers (`conio.h`, `_getch()`), so it's meant to be compiled on Windows with MinGW or MSVC.

```bash
gcc main.c -o cgrapher -lm
```

If you're using MSVC:

```bash
cl main.c /Fe:cgrapher.exe
```

---

## Usage

Run the executable and use the **arrow keys** to move through the menu, then press **Enter** to select an option.

```
  ____  ____                _
 / ___|/ ___|_ __ __ _ _ __ | |__   ___ _ __
| |     |  _| '__/ _` | '_ \| '_ \ / _ \ '__|
| |___  |_| | | | (_| | |_) | | | |  __/ |
 \____|\___|_|  \__,_| .__/|_| |_|\___|_|
                      |_|
```

### Menu options

| Option | Description |
|--------|-------------|
| Graph (Set points) | Opens the grid and lets you plot named points |
| Find distance between points | Pick two points (or origin) and get the distance |
| Find angle of a point from origin | Returns the angle in degrees |
| Find slope of a line | Calculates slope between two plotted points |
| Export results | Saves all computed values to `Export_result.html` |
| Exit | Quits the program |

### Adding points

When you're in the graph view, press `0` to add a new point. You'll be asked for X and Y coordinates (integers between -26 and 26 for them to show up on the grid). Each point gets a letter name automatically — first one is A, then B, and so on.

---

## Output

Choosing "Export results" writes an HTML file to the same directory as the executable. It lists each point's coordinates along with:

- The angle from the origin
- Slope to the next point
- Distance to the next point

Open `Export_result.html` in any browser to view it.

---

## Notes

- The slope calculation uses integer division internally, so results between points with a vertical relationship may show as undefined
- Coordinates are stored as integers — no floating point input
- Point labels are case-insensitive when selecting them in the distance/slope/angle menus
- Memory for points is dynamically allocated with `malloc`/`realloc` and freed on exit

---

## Requirements

- Windows (uses `conio.h` and `_getch`)
- GCC (MinGW) or MSVC
- Standard C math library (`-lm` for GCC)
