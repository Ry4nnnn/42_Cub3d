# 42_Cub3d

### DDA Algorithm

### Fix Fisheye Effects

---
### Print images on walls

| Variables | Purpose |
|-----------|---------|
| draw_x, draw_y | the current pixel position on the screen where the texture is start to draw |
| wall_hit       | the position on the wall where ray intersects (normalized between 0 and 1) |
| wall_index     | the index of the pixel in the texture image that correspont to the current position on the wall |
| wx, wy         | the coordinates in the texture image where to get pixel colour | 