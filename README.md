# 42_Cub3d

### DDA Algorithm

### Fix Fisheye Effects

---
### Print images on walls

The function (draw_texture) is responsible for drawing the texture on the wall by iterating over each pixel on the wall and mapping it to a corresponding pixel in the texture image. The color of the texture pixel is then retrieved and used to draw the pixel on the screen, creating the visual effect of a textured wall. The calculate_wall_hit function determines where on the wall the ray intersects, and this information is crucial for mapping the texture onto the wall accurately.

| Variables | Purpose |
|-----------|---------|
| draw.x, draw.y | the current pixel position on the screen where the texture is start to draw |
| wall_hit       | the position on the wall where ray is hitting (normalized between 0 and 1) |
| wall_index     | the index of the pixel in the texture image that correspont to the current position on the wall |
| wall.x, wall.y         | the coordinates in the texture image where to get pixel colour | 


     if (ray->side == 0) //the wall is hitting vertical walls (west or east)
    wall_hit = player->py + ray->perpwalldist * ray->diry;
else
    wall_hit = playe->px + ray->perpwalldist * ray->dirx;
wall_hit -= floor(wall_hit); //normalize it to start from 0 