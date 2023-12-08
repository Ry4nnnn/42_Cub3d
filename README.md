# 42_Cub3d
This is a simple game project inspired by Wolfenstein 3D. This project is also one of the projects in 42 core program.

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

To calculate wall_hit
```C
if (ray->side == 0) //the wall is hitting vertical walls (west or east)
    wall_hit = player->py + ray->perpwalldist * ray->diry;
else
    wall_hit = playe->px + ray->perpwalldist * ray->dirx;
wall_hit -= floor(wall_hit); //normalize it to start from 0 
```

Now we can get into a loop that start from drawstart to drawend after we set the initial draw.x and draw.y
```C
draw.x = x // x is current x coordinate on the window (also what we pass in as parameter)
draw.y = ray->drawrstart -1;
while (++draw.y <= ray->drawend)
{
    // codes that calculate wall.x, wall.y, wall_index and dest
}
```

**High overview of what this function does:**
- Iterate over each pixel vertically from the top (draw.y starts just above the top of the wall and increments until just below the bottom of the wall).
- Calculate the texture coordinates (wall.x and wall.y) based on the current pixel's position relative to the wall and the dimensions of the texture.
- Calculate the index of the pixel in the texture image (wall_index).
- Fetch the color of the pixel from the texture image (data->current_texture->addr) and assign it to cub->color.
- Draw the pixel by its colour

```C
wall.x = (int)(wall_hit * data->current_texture->width);
wall.y = (int)(((double)((draw.y - data->ray->drawstart)) / (double)data->ray->lineheight) \
                * data->current_texture->width);
wall_index = wall.x * (data->current_texture->bpp / 8) + wall.y * data->current_texture->line_length;
dest = data->current_texture->addr + wall_index;
my_mlx_pixel_put(data, SIZE_X - draw.x, draw.y, *(unsigned int*)dest);
```

---
### Contributore
- ziqiqiiii(https://github.com/ziqiqiiii)
- Ry4nnnn(https://github.com/Ry4nnnn)